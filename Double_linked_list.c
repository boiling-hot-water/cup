/*
* File: Double_linked_list.c
* Brief: Double linked list structs
* Author: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
  Creates a new node of a double linked list with key
*/
struct node* node_new(int x) { 
	struct node* node = (struct node*)malloc(sizeof(struct node)); //
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/*
  create a struct list
*/
struct list* list_new() {
	struct list* list = (struct list*)malloc(sizeof(struct list));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/*
   function deletes all elements in list
*/
void list_delete(struct list* list) {
	struct node* node = list->head;
	while (node) {
		struct node* p = node;
		node = node->next;
		free(p);
	}
	list->head = NULL;
	list->tail = NULL;
}

/*
  function pushes an element to the end of list
*/
int push(struct list* list, int x) {
	if (list->tail == NULL) {
		list->head = node_new(x);
		list->tail = list->head;
		return 1;
	}

	list->tail->next = node_new(x);
	list->tail->next->prev = list->tail;
	list->tail = list->tail->next;
	return 1;
}

/*
  
*/
int pop(struct list* list, int* px) {
	if (list->tail == NULL)
		return 0;
	
	*px = list->tail->data;
	
	if (list->tail == list->head) {
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		return 1;
	}

	struct node* prev = list->tail->prev;
	prev->next = NULL;
	free(list->tail);
	list->tail = prev;
	return 1;
}


int unshift(struct list* list, int x) {
	if (list->head == NULL) {
		list->head = node_new(x);
		list->tail = list->head;
		return 1;
	}

	list->head->prev = node_new(x);
	list->head->prev->next = list->head;
	list->head = list->head->prev;
	return 1;
}

int shift(struct list* list, int* px) {
	if (list->head == NULL)
		return 0;

	*px = list->head->data;

	if (list->tail == list->head) {
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		return 1;
	}

	struct node* next = list->head->next;
	next->prev = NULL;
	free(list->head);
	list->head = next;
	return 1;
}

void reverse(struct list* list) {
	struct node* head = list->head;
	struct node* tail = list->tail;
	
	list->head = tail;
	list->tail = head;
	
	struct node* node = head;

	while (node) {
		struct node* tmp = node->next;
		node->next = node->prev;
		node->prev = tmp;

		node = node->prev;
	}
}

void list_print(struct list* list) {
	struct node* node = list->head;

	printf("<->");
	while (node) {
		printf("[%d]<->", node->data);
		node = node->next;
	}
	printf("\n");
}
