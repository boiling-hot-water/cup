/*
 * This file is sl_list.c
 * Single linked list implementation
 */

#include <stdlib.h>
#include <stdio.h>
#include "sl_list.h"

/*
Creating list
*/
pslist slist_new(void)
{
	pslist list = malloc(sizeof(struct slist));
	if (NULL == list)
		return NULL;
	list->list_size = 0;
	list->head = NULL;

	return list;
}

/*
Head of list
*/
pslist_entry slist_pop(pslist list)
{
	struct slist_entry* pnew = malloc(sizeof(struct slist_entry));
	if (pnew == NULL)
		return NULL;
	pnew = list->head;
	if (pnew == NULL)
		return pnew;
	else {
		for (int i = 0; i < list->list_size; i++) {
			pnew = pnew->next;
		}
	}
	return pnew;
}

/* For earch element free memory */
void slist_delete(pslist list)
{
	pslist_entry head;
	while (NULL != (head = slist_pop(list)))
	{
		head->value = NULL;
		free(head);
	}
	free(list);
}

/* Insert the element at the beginning */
int slist_insert(pslist list, int value)
{
	struct slist_entry* pnew = malloc(sizeof(struct slist_entry));
	if (pnew == NULL)
		return -1;
	//pnew->value = value;
	pnew->next = list->head;
	pnew->value = value;
	list->head = pnew;
	list->list_size++;
	//pnew->next = NULL;
	return 0;
}

/* Go through the list, remove if value is equal to given value */
int slist_remove(pslist list, int value)
{
	int k = 0;
	struct slist_entry* temp = malloc(sizeof(struct slist_entry));
	if (temp == NULL)
		return -1;
	temp = list->head; 
	while (temp->value == value) {	//if value head is equal to value

		list->head = list->head->next;
		list->list_size -= 1;
		temp = temp->next;
	}
	list->head = temp;

	int l = list->list_size;
	while (temp->next != NULL) {	//if value after head is equal to value
		
		if (temp->next->value == value) {
			temp->next = temp->next->next;
			k = k + 1;
			
		}
		else {
			temp = temp->next;
		}
	}

	list->list_size -= k;
	return 0;
}

/* For each element print in value */
void slist_print(pslist list)
{
	pslist_entry pcurrent = list->head;
	printf("List: \n");
	while (pcurrent != NULL)
	{
		printf("> %d\n", pcurrent->value);
		pcurrent = pcurrent->next;
	}
}