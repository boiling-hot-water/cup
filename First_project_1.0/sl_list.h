/*
  This file is sl_list.h
  Single linked list
 */

#pragma once

 // Declaration
typedef struct slist_entry* pslist_entry;
typedef struct slist* pslist;

struct slist_entry
{
	pslist_entry next;
	int value;
};

struct slist
{
	int list_size;
	pslist_entry head;
};


/* For each element print in value */
void slist_print(pslist list);

/* Go through the list, remove if value is equal to given value */
int slist_remove(pslist list, int value);

/* Insert the element at the beginning */
int slist_insert(pslist list, int value);

/* For earch element free memory */
void slist_delete(pslist list);

/*
Head of list
*/
pslist_entry slist_pop(pslist list);

/*
Creating list
*/
pslist slist_new(void);