/*
* File: hashtable.c
* Brief: hashtable 
* Author: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT 2019
*/

#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

/*
  function insert_list inserts an element in a list 
  return the pointer to the beginning of the list
  look for an item by key in the list
  if the element is found then update the value
  if not found then add to the end of the list
*/
struct Element* insert_list(struct Element* head, char* key, int value, bool *res) {
    *res = false;
    if (head == NULL) {
        struct Element* p = (struct Element*)malloc(sizeof(struct Element));
        p->key = key;
        p->value = value;
        p->next = NULL;
        *res = true;
        return p;
    }
    struct Element* it = head;
    struct  Element* end = NULL;
    while (it != NULL && strcmp(it->key, key) != 0) {
        if (it->next == NULL) {
            end = it;
        }
        it = it->next;
    }
    if (it != NULL) {
        it->value = value;
        *res = false;
    } else {
        struct Element* p = (struct Element*)malloc(sizeof(struct Element));
        p->key = key;
        p->value = value;
        end->next = p;
        *res = true;
    }
    return head;
}
int find_list(struct Element* head, char* key) {
    struct Element* it = head;
    while (it != NULL && strcmp(it->key, key) != 0) {
        it = it->next;
    }
    if (it != NULL) {
        return it->value;
    } else return -1;
}

/*
  function removes an element of the list 
  if our key is head, free memory of it, remove its value
  if our key is something else then iterate next element
*/
struct Element* remove_list(struct Element* head, char* key) {
    struct Element* tmp;
    if (head == NULL) {
        return head;
    }
    if (head != NULL && strcmp(head->key, key) ) {
        tmp = head->next;
        free(head);
        return tmp;
    }
    struct Element* it = head;

    while (it->next != NULL && strcmp(it->next->key, key) != 0) {
        it = it->next;
    }
    tmp = it->next;
    if (tmp != NULL) {
        tmp->next = it->next;
        free(tmp);
    }
    return head;
}

/*
  function create_table initializes a hashtable
*/
struct HashTable* create_table(int n) {
    struct HashTable* h = (struct HashTable*) malloc(sizeof(struct HashTable));
    h->table = (struct Element**) malloc(n * sizeof(struct Element*));
    for (int i; i < n; ++i) {
        h->table[i] = NULL;
    }
    h->n = n;
}

/*
  polinomial function for strings
*/
int hash(char* key, int n) {
    int result = 0;
    int p = 7;
    for (int i = 0; i < strlen(key); ++i) {
        result = (result * p + (int)key[i] + 1) % n;
    }
    return result;
}

/*
  function insert_ht implements insertion in the hashtable
*/
void insert_ht(struct HashTable* h, char* key, int value, bool *res) {
    int index = hash(key, h->n);
    h->table[index] = insert_list(h->table[index], key, value, res);
}


/*
  function find_ht finds an element by key
  returns value
*/
int find_ht(struct HashTable* h, char* key) {
    return find_list(h->table[hash(key, h->n)], key);
}
