/*
* File: Double_linked_list.h
* Brief: Double linked list header
* Autor: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT 2019
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

typedef struct list list;

struct node {
	int data;
	struct node* next;
	struct node* prev;
};

struct list {
	struct node* head;
	struct node* tail;
};

void list_print(struct list*);
int brackets(char* str);
struct list* list_new();
void list_delete(struct list*);
int push(struct list*, int);
int pop(struct list*, int*);
int unshift(struct list*, int);
int shift(struct list*, int*);
void reverse(struct list*);