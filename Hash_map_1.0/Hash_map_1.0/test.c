#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"
#define TRUE 1
#define FALSE 0


int main() {
	int n;
	char* command = (char*)malloc(255 * sizeof(char));
	char* name = (char*)malloc(255 * sizeof(char));
	int number;
	scanf("%d", &n);
	struct HashTable* h = create_table(500);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", command, name);
		if (strcmp(command, "INSERT") == 0) {
			scanf("%d", &number);
		}
		if (strcmp(command, "INSERT") == 0) {
			int res = FALSE;
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

	//task_1_0(); //Task 1.10
	return 0;
}