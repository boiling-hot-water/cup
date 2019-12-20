/*
* File: hashtable.h
* Brief: hashtable header
* Author: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT 2019
*/

#pragma once

#ifndef HASHC_HASHTABLE_H
#define HASHC_HASHTABLE_H

#include <stdbool.h>

 struct Element {
    char* key;
    int value;
    struct Element* next;
} ;

struct Element* insert_list(struct Element* head, char* key, int value, bool *res);

int find_list(struct Element* head, char* key);

struct Element* remove_list(struct Element* head, char* key);

struct HashTable {
    struct Element** table;
    int n;
};

struct HashTable* create_table(int n);

int hash(char* key, int n);

void insert_ht(struct HashTable* h, char* key, int value, bool *res);

int find_ht(struct HashTable* h, char* key);


#endif //HASHC_HASHTABLE_H
