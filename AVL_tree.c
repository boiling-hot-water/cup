/*
* File: AVL_tree.c
* Brief: AVL tree structs 
* Author: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT
*/

#include <stdio.h>
#include "tree.h"

typedef struct node {
	int value;
	struct node* left, * right;
	unsigned char height;
} node;

node* create_node(int x) {
	node* n = malloc(sizeof(node));
	n->value = x;
	n->left = n->right = NULL;
	n->height = 1;
	return n;
}

node* insert_node(node* n, int x) {
	if (n == NULL)
		return create_node(x);
	if (n->value > x)
		n->left = insert_node(n->left, x);
	else
		n->right = insert_node(n->right, x);
	return n;
}

void print_node(node* n) {
	if (n == NULL)
		return;
	print_node(n->left);
	printf("%d ", n->value);
	print_node(n->right);
}

void printh_node(node* n, int h) {
	if (n == NULL)
		return;
	printh_node(n->right, h + 1);
	int i;
	printf("\e[38;5;%dm", h % 6 + 154);
	for (i = 0; i < h; ++i)
		printf("--");
	printf("|%d\n", n->value);
	printh_node(n->left, h + 1);
}

unsigned char height(node* n) {
	if (n != NULL)
		return n->height;
	else
		return 0;
}

signed char bfactor(node* n) {
	return height(n->left) - height(n->right);
}

void fix_height(node* n) {
	if (height(n->left) > height(n->right))
		n->height = height(n->left) + 1;
	else
		n->height = height(n->right) + 1;
}

node* slr(node* n) {
	node* m = n->right;
	n->right = m->left;
	m->left = n;

	fix_height(n);
	fix_height(m);
	return m;
}

node* srr(node* n) {
	node* m = n->left;
	n->left = m->right;
	m->right = n;

	fix_height(n);
	fix_height(m);
	return m;
}
