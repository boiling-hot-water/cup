/*
* File: hashtable_main.c
* Brief: hashtable main
* Author: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.c"

int main() {
    int n;
    char* command = (char*)malloc(255 * sizeof(char));
    char* name = (char*)malloc(255 * sizeof(char));
    int number;
    scanf("%d", &n);
    HashTable* h = create_table(500);
    for (int i = 0; i < n; ++i) {
        scanf("%s %s", command, name);
        if (strcmp(command, "INSERT") == 0) {
            scanf("%d", &number);
        }
        if (strcmp(command, "INSERT") == 0) {
            bool res = false;
            insert_ht(h, name, number, &res);
            if (res)
                printf("%s", "OK");
        }
        else if (strcmp(command, "FIND") == 0) {
            int number = find_ht(h, name);
            if (number != -1)
              printf("%d", number);
            else printf("%s", "NO");
        }
    }
    return 0;
}
