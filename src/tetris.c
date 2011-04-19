#include <stdio.h>
#include <termios.h>
#include <ncurses.h>
#include "tetris.h"
#include "keyev.h"
void readyToStart()
{
	int ch;
	while(0 < (ch=getch()))
	{
		if(ch == KEY_F(5))
		{
			clear();
			// start
			break;
		}
		else
		{
			//print help info
		
		}
	}
}

int main(int argc, const char *argv[])
{
	initScreen();
	readyToStart();
	evLoop();
	destroyScreen();
	return 0;
}
