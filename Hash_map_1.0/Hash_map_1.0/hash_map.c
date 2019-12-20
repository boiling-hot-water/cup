#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"
#define TRUE 1
#define FALSE 0
//using namespace std;

struct Element* insert_list(struct Element* head, char* key, int value, int* res) {//?
	*res = FALSE;
	if (head == NULL) {
		struct Element* p = (struct Element*)malloc(sizeof(struct Element));
		p->key = key;
		p->value = value;
		p->next = NULL;
		*res = TRUE;
		return p;
	}
	struct Element* it = head;
	struct Element* end = NULL;
	while (it != NULL && strcmp(it->key, key) != 0) {
		if (it->next == NULL) {
			end = it;
		}
		it = it->next;
	}
	if (it != NULL) {
		it->value = value;
		*res = FALSE;
	}
	else {
		struct Element* p = (struct Element*)malloc(sizeof(struct Element));
		p->key = key;
		p->value = value;
		end->next = p;
		*res = TRUE;
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
	}
	else return -1;
}

struct Element* remove(struct Element* head, char* key) {
	struct Element* tmp;
	if (head == NULL) {
		return head;
	}
	if (head != NULL && strcmp(head->key, key)) {
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

struct HashTable* create_table(int n) {
	struct  HashTable* h = (struct HashTable*)malloc(sizeof(struct HashTable));
	h->table = (struct Element**)malloc(n * sizeof(struct Element*));
	for (int i; i < n; ++i) {
		h->table[i] = NULL;
	}
	h->n = n;
}

int hash(char* key, int n) {
	int result = 0;
	int p = 7;
	for (int i = 0; i < strlen(key); ++i) {
		result = (result * p + (int)key[i] + 1) % n;
	}
	return result;
}

void insert_ht(struct HashTable* h, char* key, int value, int* res) {
	int index = hash(key, h->n);
	h->table[index] = insert_list(h->table[index], key, value, res);
}

int find_ht(struct HashTable* h, char* key) {
	return find_list(h->table[hash(key, h->n)], key);
}
