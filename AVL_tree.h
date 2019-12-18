/*
* File: AVL_tree.h
* Brief: AVL tree header
* Author: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT
*/

#pragma once

typedef struct node {
	int value;
	struct node* left, * right;
	unsigned char height;
}node;

node* create_node(int x);
node* insert_node(node* n, int x);
void print_node(node* n)
void printh_node(node* n, int h);

unsigned char height(node* n);
signed char bfactor(node* n);
void fix_height(node* n);
node* slr(node* n);
node* srr(node* n);
node* balance(node* n);
