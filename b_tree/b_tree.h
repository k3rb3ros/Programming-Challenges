#ifndef B_TREE_H
#define B_TREE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**************
* definitions *
**************/

// TODO refine these constants
#define MAX_KEYS 4
#define DATA_NULL -1
#define DEPTH_NULL -1

#define MAX_NODES 1024
// TODO replace with tree meta data
#define MAX_DEPTH 4
#define MAX_SUBNODES (MAX_KEYS + 1)


/********************
* types and structs *
********************/

typedef int32_t node_data_t;
typedef struct b_node_s b_node_t;
typedef struct b_tree_s b_tree_t;

/* node structure is such that
* data[0] < next[0]->keys || next[0]->keys == NULL
* next[0]->keys < data[1] < next[1]->keys || next[1]->keys == NULL
*/

// represents a b-tree node
struct b_node_s {
	node_data_t keys[MAX_KEYS];
	ssize_t num_keys;
	b_node_t* next[MAX_SUBNODES];
	ssize_t depth;
};

// represents overall b-tree structure (must be initialized and freed)
struct b_tree_s {
    b_node_t* root;
    size_t nodes_in_use;
    size_t max_nodes;
    b_node_t* next_available;
};

/*************
* comparator *
*************/

static inline bool compare_data(const node_data_t a, const node_data_t b) {
	return a < b;
}


/******************
* tree operations *
******************/

void b_tree_insert(const b_tree_t* tree, b_node_t* node, const node_data_t key);

void b_tree_insert_not_full(b_node_t* node, const node_data_t key);

void b_tree_split_child(const b_tree_t* tree, b_node_t* node);

b_node_t* b_tree_search(b_node_t* node, const node_data_t key);

void b_tree_traverse(const b_node_t* node);

void b_tree_delete(const b_tree_t* tree, b_node_t* node, const node_data_t key);


/******************
* tree management *
******************/

b_tree_t b_tree_init(void);

b_node_t* b_tree_get_new_node(b_tree_t* tree);

void b_tree_free(b_tree_t* tree);


/**********
* utility *
**********/

static inline bool is_b_tree_node_leaf(const b_node_t* node) {
	for (size_t s=0; s<MAX_SUBNODES; ++s) {
		if (node->next[s] != NULL) {
			return false;
		}
	}

	return true;
}

static inline bool is_b_tree_node_empty(const b_node_t* node) {
    bool is_empty = true;

    // only leaf leaf nodes can be empty
    if (is_b_tree_node_leaf(node)) {
        for (size_t s=0; s<MAX_KEYS; ++s) {
            // any non NULL keys in a node indicate its not empty
            if (node->keys[s] != DATA_NULL) {
                is_empty = false;
                break;
            }
        }
    }

    is_empty = node->depth > DEPTH_NULL ? false : is_empty;
    return is_empty;
}

void print_tree(b_tree_t* n);

#endif
