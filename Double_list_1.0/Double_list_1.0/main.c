/*
* File: Double_linked_list_main.c
* Brief: Double linked list main
* Author: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	struct list* list = list_new();

	list_print(list);

	int i;
	for (i = 0; i < 5; ++i)
		push(list, i);
	list_print(list);

	int x;
	while (pop(list, &x)) {
		list_print(list);
	}

	for (i = 0; i < 5; ++i)
		unshift(list, 10 - i);
	list_print(list);
	reverse(list);
	list_print(list);

	while (shift(list, &x)) {
		list_print(list);
	}
	
	/*char* str = (char*)malloc(255 * sizeof(char));
	scanf("%s", str);
	int retur_n = brackets(str);*/
	
	return 0;
}