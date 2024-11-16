#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// TODO refine these constants
#define MAX_DATA 4
#define DATA_NULL -1
#define DEPTH_NULL -1

#define MAX_NODES 1024
#define MAX_DEPTH 4
#define MAX_SUBNODES 6

// type definitions
typedef int32_t node_data_t;
typedef struct b_node_s b_node_t;

// struct definitions
struct b_node_s {
	int32_t depth;
	node_data_t data[MAX_DATA];
	b_node_t* next[MAX_SUBNODES];
};

// helper functions

// safely init all values in the passed in node
// returns a pointer to the same node
static inline b_node_t* init_node(b_node_t* n) {
	if (n != NULL) {
		n->depth = DEPTH_NULL;

		for (size_t s=0; s<MAX_DATA; ++s) {
			n->data[s] = DATA_NULL;
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

// frees the block of memory to the nodes in nodes_on_heap
static inline void free_nodes(b_node_t* nodes_on_heap) {
	free(nodes_on_heap);
}

static inline bool node_empty(const b_node_t* n) {
	// check for node ptrs
	for (size_t s=0; s<MAX_SUBNODES; ++s) {
		if (n->next[s] != NULL) {
			return false;
		}
	}
	// check for set depth
	return (n->depth >= 0) ? false : true;
}

// function specialized to print node data
static inline void print_node_data(const node_data_t* d) {
	printf("data: [ ");
	for(size_t s=0; s<MAX_DATA; ++s) {
		printf("%d ", d[s]);
	}
	printf("] ");
}

static inline void print_ptrs(const b_node_t* n) {
	printf("nodes: ");
	for (size_t s=0; s<MAX_SUBNODES; ++s) {
		if (n->next[s] == NULL) {
			printf("() ");
		}
		else {
			assert(n->next[s] != NULL);\
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

static inline void print_node(const b_node_t* n, const bool print_addr) {
	if (n == NULL) {
		return;
	}
	if (print_addr) {
		printf("node: %p ", (void*)n);
	}
	else {
		printf("node: ");
	}
	print_node_data(n->data);
	print_ptrs(n);
}

// prints the complete tree passed into the function
// assumes all nodes are allocated in a contiguous array with
// a node is considered to be "used" when it is assigned a depth >= 0
void print_tree(b_node_t* n) {
	if (n == NULL) {
		return;
	}

	b_node_t* matched_nodes[MAX_NODES] = { NULL };

	for (int32_t s=0; s<MAX_DEPTH; ++s) {
		clear_node_arr(matched_nodes, MAX_NODES);
		size_t match_ind = 0;

		for (size_t t=0; t<MAX_NODES; t++) {
			// find all non empty nodes of the given depth
			if (!node_empty(&n[t]) && n[t].depth == s) {
				matched_nodes[match_ind++] = &n[t];
			}
		}

		// if any nodes of this depth exist print them
		if (match_ind > 0) {
			printf("depth: %d ", s);

			for (size_t t=0; t<MAX_NODES; t++) {
				if (matched_nodes[t] != NULL) {
					print_node(matched_nodes[t], false);
				}
			}

			printf("\n");
		}
	}
}

int32_t main(void) {
	b_node_t* nodes = allocate_and_init_nodes(MAX_NODES);
	// get ptr to root node
	b_node_t* root = &nodes[0];
	// set up root node
	root->depth = 0;
	root->next[0] = &nodes[1];
	nodes[1].depth = 1;

	print_tree(nodes);

	free_nodes(nodes);
	nodes = NULL;

	return 1;
}
