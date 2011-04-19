#include <stdlib.h>
#include <string.h>
#include "llist.h"
List *listCreate()
{
	List *list = (List*)malloc(sizeof(List));
	memset(list,0,sizeof(List));
	return list;
}
void listInsert(Node *node,Iter *loc)
{
	if( !(loc && loc->loc) || !node)
		return ;
	loc->loc->next = node;
	node->prev = loc->loc->prev;
	node->next = loc->loc;
	loc->loc->prev = node;
}
void listDelete(Iter *loc)
{
	if(loc && loc->loc && loc->loc->prev)
		loc->loc->prev->next=loc->loc->next;
	if(loc && loc->loc && loc->loc->next)
		loc->loc->next->prev = loc->loc->prev;
	if(loc && loc->loc)
		free(loc->loc);
}
int NodeUpdate(Iter *loc,Node *node)
{
	if(loc && loc->loc && loc->loc->value)
	{
		free(loc->loc->value);
		loc->loc->value = node->value;
		return 1;
	}
	return 0;
}
Node *listFirst(List *list)
{
	return list->head;
}
Node *listLast(List *list)
{
	return list->tail;
}
void listrPush(List *list ,Node *node)
{
	if(list->tail !=NULL)
	{
		list->tail->next = node;
		node -> prev = list->tail;
		node ->next = NULL;
		list->tail = node;
	}
	else
	{
		list->tail = node;
		list->head = node;
		node->next = NULL;
		node->prev = NULL;
	}
}
void listlPush(List *list ,Node *node)
{
	if(list->head != NULL)
	{
		list->head->prev = node;
		node->prev = NULL;
		node->next = list->head;
		list->head = node;
	}
	else
	{
		list->tail = node;
		list->head = node;
		node->prev = NULL;
		node->next = NULL;
	}
}
void listFree(List *list)
{
	Iter iter;
	iter.loc = list->head;
	while(iter.loc != NULL)
	{
		Node *node = iter.loc;
		iter.loc = iter.loc->next;
		free(node);
	}
}

