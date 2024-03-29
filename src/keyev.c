#include "keyev.h"
#include <stdlib.h>
#include <string.h>

int initEventList()
{
	size_t i ;
	for( i = 0 ;i < EVENT_COUNT ; ++i)	
	{
		List *list = (List *)malloc(sizeof(List));
		if(!list)return E_ERR;
		memset(list,0,sizeof(List));
		events[i] = list;

	}
	return E_OK;
}
int freeEventList()
{
	size_t i ;
	for(i = 0 ;i < EVENT_COUNT ; ++i)	
	{
		if(events[i])
			listFree(events[i]);
	}
	return E_OK;
}
Iter eventsAdd(KEY_EVENT_ENUM type, EVENT_PROC* proc)
{
	Iter iter;
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = proc;
	listrPush(events[type],node);
	iter.loc = node;
	return iter;
}
int eventsDel(Iter iter)
{
	listDelete(&iter);
	return E_OK;
}
static int call(KEY_EVENT_ENUM type)
{
	Iter it;
	if(!events[type]) return E_ERR;
	it.loc= events[type]->head;
	while(it.loc !=NULL)
	{
		if(it.loc->value)
			((EVENT_PROC*)(it.loc->value))();
	}
	return E_OK;

};

int evLoop()
{
	int c ;
	while((c = getch())>0)
	{
		switch (c){
			case KEY_UP:
				call(KEV_UP);
				break;
			case KEY_DOWN:
				call(KEV_DOWN);
				break;
			case KEY_LEFT:
				call(KEV_LEFT);
				break;
			case KEY_RIGHT:
				call(KEV_RIGHT);
				break;
			case 0x20:
				call(KEV_SPACE);
				break;
			default:break;

		}
	}
	return 0;
}
