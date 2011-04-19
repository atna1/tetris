#include "wins.h"
WINDOW *createWin(int nlines, int ncols,int begin_y,int begin_x)
{
	WINDOW *win = newwin(nlines,ncols,begin_y,begin_x);
	box(win,0,0);
	wrefresh(win);
	return win;
}
void initScreen()
{
	initscr();
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	printw("Press F5 to start");
	refresh();

}
void destroyScreen()
{
	endwin();
}
void initWin(WINDOW *right, WINDOW *left)
{
	right = createWin(40,50,1,0);
	left = createWin(40,30,1,51);
}
