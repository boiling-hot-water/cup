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
  сreate a new node of a double linked list with key
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
  set the pointer NULL to the head and tail
*/
struct list* list_new() {
	struct list* list = (struct list*)malloc(sizeof(struct list));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/*
   function deletes all elements in list
   until we get to the end of the list, delete all elements
   free memory
   set the pointer NULL to the head and tail
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
  function pushes an element to the end (tail) of list
  if we don’t have a tail, then we return 1
  create an element after tail
  now this element is a tail and past tail is previous before current
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
  function pop extracts the last element in a list
  if a tail of the list is empty, return 0
  create a pointer to the tail value
  if the list has just one element, free memory, delete elements
  (if the tail is the head, then remove the head)
  if the next element after this element is empty, that is, it is not there, then delete this element
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

/*
  function unshift adds an element to the beginning of the list
  if a head of the list is empty, return 1
  create an element of the structure
  the next one is the head
  now new element is the head
*/
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

/*
  function shift retrieves the first element of a list
  if a head of the list is empty, return 1
  create a pointer to the head value 
  if the list has just one element, free memory, delete elements
  create a pointer to the next element after head
  free memory of the current head
  now head of the list is next after it
*/
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

/*
  function reverse inverts the list the link to which receives as an argument
  create the pointer to the head of the list
  create the pointer to the tail of the list
  next element of the list becomes last
*/
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

/*
  function list_print prints something like little dashes for the beauty
*/
void list_print(struct list* list) {
	struct node* node = list->head;

	printf("<->");
	while (node) {
		printf("[%d]<->", node->data);
		node = node->next;
	}
	printf("\n");
}
