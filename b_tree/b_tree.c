#include "b_tree.h"
#include <assert.h>
#include <stdio.h>


/********************
* Utility functions *
*********************/

// safely init all values in the passed in node
// returns a pointer to the same node
static inline b_node_t* init_node(b_node_t* n) {
	if (n != NULL) {
		n->depth = DEPTH_NULL;
		n->num_keys = 0;

		for (size_t s=0; s<MAX_KEYS; ++s) {
			n->keys[s] = DATA_NULL;
		}
		for (size_t s=0; s<MAX_SUBNODES; ++s) {
				n->next[s] = NULL;
		}
	}

	return n;
}

// allocate storage to a contiguous block of nodes of size num_nodes
// returns a pointer to the first node or NULL on failure
static inline b_node_t* allocate_and_init_nodes(const size_t num_nodes) {
	// node structure only makes sense if this is true
	assert(MAX_SUBNODES == (MAX_KEYS + 1));

	// allocate storage for nodes
	b_node_t* allocated_nodes = malloc(num_nodes * sizeof(b_node_t));

	if (allocated_nodes == NULL) {
		fprintf(stderr, "Error allocating nodes");
		return NULL;
	}

	for (size_t s=0; s<MAX_NODES; ++s) {
		if (init_node(&allocated_nodes[s]) == NULL) {
			fprintf(stderr, "Error allocating nodes");
			return NULL;
		}
	}

	return allocated_nodes;
}


b_tree_t b_tree_init(void) {
	b_tree_t tree;

	tree.root = allocate_and_init_nodes(MAX_NODES);
	tree.nodes_in_use = 1;
	tree.max_nodes = MAX_NODES;
	tree.next_available = (tree.root + sizeof(b_node_t));

	return tree;
}

b_node_t* b_tree_get_new_node(b_tree_t* tree) {
	b_node_t* node = NULL;

	if (tree != NULL && tree->nodes_in_use <= tree->max_nodes) {
		node = tree->next_available;
		tree->next_available++;
		tree->nodes_in_use++;
	}

	return node;
}

void b_tree_free(b_tree_t* tree) {
	free(tree->root);
	tree->root = NULL;
	tree->next_available = NULL;
	tree->nodes_in_use = 0;
}

// function specialized to print node data
static inline void print_node_keys(const b_node_t* node) {
	printf("keys: [ ");
	for (ssize_t s=0; s<node->num_keys; ++s) {
		printf("%d ", node->keys[s]);
	}
	printf("] ");
}

static inline void print_ptr_state(const b_node_t* node) {
	printf("ptrs: ");
	for (size_t s=0; s<MAX_SUBNODES; ++s) {
		if (node->next[s] == NULL) {
			printf("O ");
		}
		else {
			assert(node->next[s] != NULL);\
			printf("* ");
		}
	}
}

// helper function to clear node arr
static inline void clear_node_arr(b_node_t* n[], const size_t len) {
	for (size_t s=0; s<len; ++s) {
		n[s] = NULL;
	}
}

static inline void print_node(const b_node_t* node, const bool print_addr) {
	// printf("print_node(%p)\n", (void*)node);
	if (node == NULL) {
		return;
	}
	if (print_addr) {
		printf("node: %p ", (void*)node);
	}
	else {
		printf("node: ");
	}
	print_node_keys(node);
	print_ptr_state(node);
	if (is_b_tree_node_leaf(node)) {
		printf("leaf ");
	}
}

// prints the complete tree passed into the function
// assumes all nodes are allocated in a contiguous array with
// a node is considered to be "used" when it is assigned a depth >= 0
void print_tree(b_tree_t* tree) {
	if (tree == NULL) {
		return;
	}

	b_node_t** matched_nodes = { NULL };
	matched_nodes = calloc(tree->max_nodes, sizeof(b_node_t*));
	// printf("print_tree(%p)\n", (void*)n);

	for (ssize_t s=0; s<MAX_DEPTH; ++s) {
		b_node_t* n = tree->root;
		clear_node_arr(matched_nodes, MAX_NODES);
		size_t match_ind = 0;

		for (size_t t=0; t<tree->max_nodes; t++) {
			// find all non empty nodes of the given depth
			if (!is_b_tree_node_empty(&n[t]) && n[t].depth == s) {
				matched_nodes[match_ind++] = &n[t];
			}
		}

		// if any nodes of this depth exist print them
		if (match_ind > 0) {
			printf("depth: %zd ", s);

			for (size_t t=0; t<tree->max_nodes; t++) {
				if (matched_nodes[t] != NULL) {
					print_node(matched_nodes[t], false);
				}
			}

			printf("\n");
		}
	}

	free (matched_nodes);
	matched_nodes = NULL;
}

void b_tree_insert(b_tree_t* tree, const node_data_t key) {
	// operations not defined if tree not inited
	if (tree != NULL) {
		// Root full tree grows in height
		if (is_b_tree_node_full(tree->root))
		{
			b_node_t* new_root = b_tree_get_new_node(tree);
			b_node_t* old_root = tree->root;

			// make old root child of new root
			old_root->depth++;
			new_root->next[0] = tree->root;

			// Split the old root and move 1 key to the new root
			b_tree_split_child(tree, old_root, 0);

			// New root has two children now. Decide which of the
			// two children is going to have new key
			ssize_t i=0;
			if (new_root->keys[i] < key) {
				i++;
			}
			assert(new_root->keys[i] != DATA_NULL);
			b_node_t* insert_tgt = new_root->next[i];
			b_tree_insert_not_full(insert_tgt, key);

			// update root
			tree->root = new_root;
		}
		// root not full so just insert in root
		else {
			b_tree_insert_not_full(tree->root, key);
		}
	}
}

b_node_t* b_tree_search(b_node_t* node, const node_data_t key) {
	b_node_t* search_result = NULL;

	if (node != NULL) {
		node_data_t i = 0;

		// traverse keys from left to right
		while (i < node->num_keys && key < node->keys[i] && i < MAX_KEYS) {
			i++;
		}

		// check if key is in this node
		if (i < node->num_keys && key == node->keys[i]) {
			search_result = node;
		}
		// leaf nodes have no children so if it's not in the key isn't in a given leaf node than it isn't
		// in the tree
		else if (is_b_tree_node_leaf(node)) {
			search_result = NULL;
		}
		else {
			// otherwise recursively check sub nodes for key range
			search_result = b_tree_search(node->next[i], key);
		}
	}

	return search_result;
}

int32_t main(void) {
	b_tree_t tree = b_tree_init();
	// set up root node
	tree.root->depth = 0;
	b_node_t* n1 = b_tree_get_new_node(&tree);
	tree.root->next[0] = n1;
	n1->depth = 1;
	n1->keys[0] = 2;
	n1->num_keys = 1;

	print_tree(&tree);

	b_tree_free(&tree);

	return 1;
}
