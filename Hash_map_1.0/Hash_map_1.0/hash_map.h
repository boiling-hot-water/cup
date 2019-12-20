

#pragma once
//typedef struct struct Element Element;
//typedef struct HashTable HashTable;
struct Element {
	char* key;
	int value;
	struct Element* next;
} ;

struct HashTable {
	struct Element** table;
	int n;
};


struct Element* insert_list(struct Element* head, char* key, int value, int* res);

int find_list(struct Element* head, char* key);

struct Element* remove(struct Element* head, char* key);

struct HashTable* create_table(int n);

int hash(char* key, int n);

void insert_ht(struct HashTable* h, char* key, int value, int* res);

int find_ht(struct HashTable* h, char* key);

void task_1_0();