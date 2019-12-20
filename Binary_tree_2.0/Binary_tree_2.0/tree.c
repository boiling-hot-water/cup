/*
 * This file is tree.c
 * Binary Search Tree imlpementation
 *
 */

#include <stdio.h>
 //#include <stdlib.h>
#include "tree.h"

FILE* g_log;

/*
Openning log file for testing
*/
int init_log(void)
{
	g_log = fopen("log.txt", "w+");
	if (NULL == g_log)
	{
		printf("Can't create log file\n");
		return FALSE;
	}
	fprintf(g_log, "init_log()\n");
	return TRUE;
}

/*
Closing log file for testing
*/
void deinit_log(void)
{
	fprintf(g_log, "deinit_log()\n");
	fclose(g_log);
}

/*
Printing values and keys of tree
Deeping realization
*/
void deep_print(TREE_NODE* tree) {
	if (tree) {
		printf("%d %f\n", tree->key, tree->value);
		preOrderTravers(tree->left);
		preOrderTravers(tree->right);
	}
}

/*
Printing values and keys of tree
Widthing realization
*/
void width_print(TREE_NODE* tree) {

}


/*
Adding node to the tree
Set values key and value to the inbox parameters
*/
TREE_NODE* add_node(TREE_NODE* tree, int key, float value)
{
	fprintf(g_log, "add_node(%p, %d, %f)\n", tree, key, value);

	if (NULL == tree)
	{
		TREE_NODE* tmp = malloc(sizeof(TREE_NODE));
		if (NULL == tmp)
			return NULL;
		tmp->key = key;
		tmp->value = value;
		tmp->parent = NULL;
		tmp->left = tmp->right = NULL;
		tree = tmp;
	}
	else if (tree->key < key)
		tree->left = add_node(tree->left, key, value);
	else
		tree->right = add_node(tree->right, key, value);

	return tree;
}

/*
Extra function for delete_node(TREE_NODE tree, int key)
Searching next element for some node
*/
TREE_NODE* next_element(TREE_NODE* tree)
{
	TREE_NODE* p = tree, * l = NULL;
	if (p->right != NULL) {
		l = p->right;
		while (l->left != NULL) {
			l = l->left;
		}
		return l;
	}
	l = p->parent;
	while ((l != NULL) && (p == l->right))
	{
		p = l;
		l = l->parent;
	}
	return l;
}

/*
Extra function for delete_node(TREE_NODE tree, int key)
Searching element in the tree on his key
Realized as recursive binsearch
*/
TREE_NODE* search(TREE_NODE* tree, int key)
{
	if ((tree == NULL) || (tree->key = key))
		return tree;
	if (key < tree->key)
		return search(tree->left, key);
	else return search(tree->right, key);
}

/*
Deleting some element on his key
*/
TREE_NODE* delete_node(TREE_NODE* tree, int key)
{
	fprintf(g_log, "delete_node(%p, %d)\n", tree, key);
	// Поиск удаляемого узла по ключу
	TREE_NODE* p = tree, * l = NULL, * m = NULL;
	l = search(tree, key);
	// When this element is dead end branch
	if ((l->left == NULL) && (l->right == NULL))
	{
		m = l->parent;
		if (l == m->right) m->right == NULL;
		else m->left == NULL;
		free(l);
	}
	// When this element has right branch
	if ((l->left == NULL) && (l->right != NULL))
	{
		m = l->parent;
		if (l == m->right) m->right == l->right;
		else m->left == l->right;
		free(l);
	}
	// When this element has left branch
	if ((l->left != NULL) && (l->right == NULL))
	{
		m = l->parent;
		if (l == m->right) m->right == l->left;
		else m->left == l->left;
		free(l);
	}
	//  When this element has a lot of branches below
	if ((l->left != NULL) && (l->right != NULL))
	{
		m = next_element(l);
		l->key = m->key;
		if (m->right == NULL)
			m->parent->left = NULL;
		else m->parent->left = m->right;
		free(m);
	}
	return tree;
}

/*
Destroy tree and free memory
*/
void destroy_tree(TREE_NODE* tree)
{
	fprintf(g_log, "destroy_tree(%p)\n", tree);
	if (tree == NULL)
		return 0;
	destroy_tree(tree->left);
	destroy_tree(tree->right);
	if (tree->key) {
		//printf("%d ", tree->key);
		free(tree);
	}
}

/*
Init tree and set NULL to parent, left and right branch
*/
TREE_NODE* init_tree(void) {
	TREE_NODE* tmp = malloc(sizeof(TREE_NODE));
	if (NULL == tmp)
		return NULL;
	tmp->key = NULL;
	tmp->value = NULL;
	tmp->parent = NULL;
	tmp->left = tmp->right = NULL;

	fprintf(g_log, "init_tree(%p)\n", tmp);
	return tmp;
}