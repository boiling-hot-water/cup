/*
 * This file is tree.h
 * New Year Tree
 *
 */

#pragma once

#define FALSE 0
#define TRUE 1

typedef struct _TREE_NODE
{
	int key;
	float value;
	struct _TREE_NODE* left;
	struct _TREE_NODE* right;
	struct _TREE_NODE* parent;
} TREE_NODE;


extern FILE* g_log;

TREE_NODE* init_tree(void);

/*
Openning log file for testing
*/
int init_log(void);

/*
Closing log file for testing
*/
void deinit_log(void);

/*
Init tree and set NULL to parent, left and right branch
*/
TREE_NODE* init_tree(void);

/*
Destroy tree and free memory
*/
void destroy_tree(TREE_NODE* tree);

/*
Deleting some element on his key
*/
TREE_NODE* delete_node(TREE_NODE* tree, int key);

/*
Extra function for delete_node(TREE_NODE tree, int key)
Searching element in the tree on his key
Realized as recursive binsearch
*/
TREE_NODE* search(TREE_NODE* tree, int key);

/*
Extra function for delete_node(TREE_NODE tree, int key)
Searching next element for some node
*/
TREE_NODE* next_element(TREE_NODE* tree);

/*
Adding node to the tree
Set values key and value to the inbox parameters
*/
TREE_NODE* add_node(TREE_NODE* tree, int key, float value);

/*
Printing values and keys of tree
Deeping realization
*/
void deep_print(TREE_NODE* tree);

/*
Printing values and keys of tree
Widthing realization
*/
void width_print(TREE_NODE* tree);