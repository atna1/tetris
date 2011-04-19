#include "../llist.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	List * list = listCreate();
	for(int i = 0 ; i < 10 ; ++i)
	{
		Node *node = (Node *)malloc(sizeof(Node));
		int *value = (int *)malloc(sizeof(int));
		*value = i;
		node->value = value;
		listrPush(list,node);
	}
	Iter iter;
	iter.loc=list->head;
	while(iter.loc != NULL)
	{
		int *value = (int*)iter.loc->value;
		printf("%d ",*value);
		iter.loc=iter.loc->next;
	}
	return 0;
}
