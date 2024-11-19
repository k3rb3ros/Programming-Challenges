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

	tree.nodes = allocate_and_init_nodes(MAX_NODES);
	tree.root = &tree.nodes[0];
	tree.root->depth = 0;
	tree.nodes_in_use = 1;
	tree.max_nodes = MAX_NODES;
	tree.next_available = (tree.root + sizeof(b_node_t));

	return tree;
}

b_node_t* b_tree_get_new_node(b_tree_t* tree) {
	b_node_t* node = NULL;

	// TODO reallocate larger node space and rebuild tree if we hit max_nodes
	if (tree != NULL && tree->nodes_in_use <= tree->max_nodes) {
		node = tree->next_available;
		tree->next_available++;
		tree->nodes_in_use++;
	}

	return node;
}

void b_tree_free(b_tree_t* tree) {
	free(tree->nodes);
	tree->root = NULL;
	tree->nodes = NULL;
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
		b_node_t* n = tree->nodes;
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

void b_tree_insert_not_full(b_tree_t* tree, b_node_t* node, const node_data_t key) {
	// Initialize index as index of rightmost element
	ssize_t i = (node->num_keys - 1);
	// this function only works correctly on non full nodes
	assert(!is_b_tree_node_full(node));

	if (is_b_tree_node_leaf(node)) {
		// find point to insert new key
		while (i >=0 && node->keys[i] > key) {
			// move all keys > new key to the right
			node->keys[i+1] = node->keys[i];
			i--;
		}

		// insert new key
		node->keys[i+1] = key;
		node->num_keys++;
	}
	else { // non leaf node
		assert(!is_b_tree_node_leaf(node));
		// find the child that is going to have the new key
		while (i >=0 && node->keys[i] > key) { i--; }

		// If the child is full
		if (is_b_tree_node_full(node->next[i+1])) {
			// split it into two nodes
			b_tree_split_child(tree, node, node->next[i+1], i+1);

			// After split, the middle key of next[i] goes up and
            // next[i] is split into two. See which of the two
            // is going to have the new key
			if (node->keys[i+1] < key) {
				i++;
			}
		}
		// insert the new key into the child node
		b_tree_insert_not_full(tree, node->next[i+1], key);
	}
}

void b_tree_split_child(
    b_tree_t* tree,
    b_node_t* parent,
    b_node_t* child,
    const ssize_t ind_to_split_on) {
	assert(tree != NULL);
	assert(parent != NULL);
	assert(child != NULL);
	assert(parent != child);
	// this function only works correctly on full nodes
	assert(is_b_tree_node_full(child));
	assert(ind_to_split_on < MAX_SUBNODES-1);

	// allocate new child node
	b_node_t* new_child = b_tree_get_new_node(tree);
	if (new_child == NULL) {
		fprintf(stderr, "b_tree_split_child() memory allocation of new node failed\n");
		return;
	}

	// set depth
	new_child->depth = child->depth;

	// Copy the last (MAX_KEYS-T) keys of child to new_child
	for (ssize_t k=T,l=0; k<MAX_KEYS; ++k,++l) {
		new_child->keys[l] = child->keys[k];
		child->keys[k] = DATA_NULL;
		child->num_keys--;
		new_child->num_keys++;
	}

	// Copy the last T children of child to new_child (if not leaf node)
	if (!is_b_tree_node_leaf(child)) {
		for (ssize_t n=T,o=0; n<MAX_SUBNODES; ++n, ++o) {
            new_child->next[o] = child->next[n];
		}
	}

	assert(parent->next[MAX_SUBNODES-1] == NULL);
	// Since this node is going to have a new child,
    // create space for the new child
	for (ssize_t n=(ind_to_split_on+1); n<(MAX_SUBNODES-1); ++n) {
		parent->next[n+1] = parent->next[n];
	}

	// Link the new child to this node
	parent->next[ind_to_split_on + 1] = new_child;

	assert(parent->num_keys < MAX_KEYS);
	// A key of child will move to parent. Find the location of
    // new key and move all greater keys one space ahead
	for (ssize_t k=(parent->num_keys-1); k >= ind_to_split_on; --k) {
        parent->keys[k + 1] = parent->keys[k];
	}

	// Copy the rightmost key of child to parent
	parent->keys[ind_to_split_on] = child->keys[child->num_keys - 1];
	child->keys[child->num_keys - 1] = DATA_NULL;

	// Update key count
	child->num_keys--;
	parent->num_keys++;
}

void b_tree_insert(b_tree_t* tree, const node_data_t key) {
	// operations not defined if tree not inited
	if (tree != NULL) {
		// Root full tree grows in height
		if (is_b_tree_node_full(tree->root))
		{
			b_node_t* new_root = b_tree_get_new_node(tree);
			b_node_t* old_root = tree->root;

			if (new_root == NULL) {
				fprintf(stderr, "b_tree_insert() memory allocation of new node failed\n");
				return;
			}

			// make old root child of new root
			old_root->depth++;
			// TODO increase depth of all old_root nodes
			new_root->next[0] = old_root;
			new_root->depth = 0;

			// Split the old root and move 1 key to the new root
			b_tree_split_child(tree, new_root, old_root, 0);

			// New root has two children now. Decide which of the
			// two children is going to have new key
			ssize_t i = 0;
			if (new_root->keys[i] < key) {
				i++;
			}
			assert(!is_b_tree_node_empty(new_root));
			b_node_t* insert_tgt = new_root->next[i];
			b_tree_insert_not_full(tree, insert_tgt, key);

			// update root
			tree->root = new_root;
		}
		// root not full so just insert in root
		else {
			b_tree_insert_not_full(tree, tree->root, key);
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

	for (node_data_t d=1; d<=100; ++d) {
		b_tree_insert(&tree, d);
	}

	print_tree(&tree);

	b_tree_free(&tree);

	return 0;
}
