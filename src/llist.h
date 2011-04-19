/*
 * Link list 
 * author:renenglish
 * date : 2011-04-19
 * */
#ifndef __LLIST_H
#define __LLIST_H

typedef struct Node{
	void *value;
	struct Node *prev;
	struct Node *next;
}Node; 
typedef struct List{
	int len;
	Node *head;
	Node *tail;
}List;
typedef struct Iter{
	Node *loc;
}Iter;

List *listCreate();
void listInsert(Node *node, Iter *loc);
void listDelete(Iter *loc);
void listUpdate(Iter *loc,Node *node);
Node *listFirst(List *list);
Node *listLast(List *list);
void listrPush(List *list, Node *node);
void listlPush(List *list,Node *node);
void listFree(List *list);

#endif
