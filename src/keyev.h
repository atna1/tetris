#ifndef __KEYEV__H
#define __KEYEV__H
#include <ncurses.h>
#include "llist.h"
#define EVENT_COUNT 5
#define E_OK 1
#define E_ERR 0

typedef enum KEY_EVENT_ENUM
{
	KEV_UP=0,
	KEV_DOWN=1,
	KEV_LEFT=2,
	KEV_RIGHT=3,
	KEV_SPACE=4
} KEY_EVENT_ENUM ;

typedef struct Keyev{
		
}Keyev;
/*typedef struct EventList{ // because event list require frequency insert/delete, we should store them with linklist

}EventList;*/
typedef struct List EventList;
typedef void (EVENT_PROC)() ;
EventList* events[EVENT_COUNT];
int initEventList();
Iter eventsAdd(KEY_EVENT_ENUM type, EVENT_PROC *proc);
int eventsDel(Iter iter);
int evLoop();
#endif
