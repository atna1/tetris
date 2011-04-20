#include <stdio.h>
#include <termios.h>
#include "tetris.h"
#include "keyev.h"
void readyToStart()
{
	int ch;
	while(0 < (ch=getch()))
	{
		if(ch == KEY_F(5))
		{
	//		clear();
			// start
			break;
		}
		else
		{
			//print help info
		
		}
	}
}
void moveLeftHandler()
{
	WINDOW * win = scr.wins[RIGHT]->wfd;
	//wprintw(win,"%s",L1[0]);
	wprintw(win,"key left arraw");
	wrefresh(win);
}
void moveRigthHandler()
{

}
void graphicChange()
{

}
void pauseOrStart()
{

}
void registerHandler()
{
	initEventList();
	eventsAdd(KEV_UP,graphicChange);
	eventsAdd(KEV_LEFT,moveLeftHandler);
}

int main(int argc, const char *argv[])
{
	initScreen();
	registerHandler();
	readyToStart();
	evLoop();
	destroyScreen();
	return 0;
}
