/*
* File: 1.2.c
* Author: Arina Chumachenko <chumachenko.as@phystech.edu>
* (c) MIPT 2019
*/

#include <stdio.h>
#include "sl_list.h"

int first_integers(int n)
{
	pslist list = slist_new();

	for (int i = 0; i < n; i++)
     slist_insert(list, i);

	return list;
}

int main(void)
{
	pslist = first_integers(100);
	return 0;
}
