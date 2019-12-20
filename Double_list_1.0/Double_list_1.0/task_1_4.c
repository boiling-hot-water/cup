#include <stdio.h>
#include "double_list.h"
#include <string.h>

#define FALSE 0
#define TRUE 1
#define _CRT_SECURE_NO_WARNINGS

int brackets(char* str)
{
	list* list = list_new();
	int* tmp = NULL;
	int curr, retur_n, i = 0;
	int s = strlen(str);
	printf("%d", s);
	for (i = 0; i < s; ++i)
	{
		if (str[i] != '{' || str[i] != '(' || str[i] != '[' || str[i] != ')' || str[i] != '}' || str[i] != ']')
		{
			printf("Input are not brackets\n");
			return FALSE;
		}
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
		{
			if (str[i] == '{')
			{
				curr = 1;
			}
			if (str[i] == '(')
			{
				curr = 2;
			}
			if (str[i] == '[')
			{
				curr = 3;
			}
			retur_n = push(list, curr);
		}

		if (str[i] == '}' || str[i] == ')' || str[i] == ']')
		{
			retur_n = pop(list, tmp);
			if (str[i] == '}' && *tmp != 1)
			{
				printf("Expression is not correct\n");
				return FALSE;
			}
			if (str[i] == ')' && *tmp != 2)
			{
				printf("Expression is not correct\n");
				return FALSE;
			}
			if (str[i] == ']' && *tmp != 3)
			{
				printf("Expression is not correct\n");
				return FALSE;
			}
		}
	}
	printf("Expression is correct\n");
	return TRUE;
}