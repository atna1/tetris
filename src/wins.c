#include "wins.h"
//global windows 

WINDOW *createWin(int nlines, int ncols,int begin_y,int begin_x)
{
	WINDOW *win = newwin(nlines,ncols,begin_y,begin_x);
	box(win,0,0);
	wrefresh(win);
	return win;
}
void initScreen()
{
	ensureLayOut();
	initscr();
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	printw("Press F5 to start");
	refresh();
	winRigth.wfd =  createRightWin();
	winLeft.wfd = createLeftWin();
	winLeftTop.wfd = createLeftTopWin();
	winLeftBottom.wfd = createLeftBottomWin();

	//add to screen
	scrAddWin(&scr,&winRigth,RIGHT);
	scrAddWin(&scr,&winLeft,LEFT);
	scrAddWin(&scr,&winLeftTop,LEFT_TOP);
	scrAddWin(&scr,&winLeftBottom,LEFT_BOTTOM);

}
void destroyScreen()
{
	endwin();
}
void ensureLayOut()
{
	winRigth.nlines = 40;
	winRigth.ncols = 70;
	winRigth.begin_y = 1;
	winRigth.begin_x = 0;

	winLeft.nlines = 40 ;
	winLeft.ncols = 30;
	winLeft.begin_y = 1;
	winLeft.begin_x = winRigth.ncols + 5;

	winLeftTop.nlines = (winLeft.nlines*1)/3;
	winLeftTop.ncols = winLeft.ncols;
	winLeftTop.begin_y = winLeft.begin_y;
	winLeftTop.begin_x = winLeft.begin_x;

	winLeftBottom.nlines = winLeftTop.nlines;
	winLeftBottom.ncols = winLeft.ncols;
	winLeftBottom.begin_y = winLeft.begin_y+winLeft.nlines-winLeftBottom.nlines;
	winLeftBottom.begin_x = winLeft.begin_x;

}

WINDOW *createRightWin()
{
	WINDOW * win = createWin(winRigth.nlines, winRigth.ncols,winRigth.begin_y,winRigth.begin_x);
	return win;
}
WINDOW *createLeftWin()
{
	WINDOW * win = createWin(winLeft.nlines, winLeft.ncols,winLeft.begin_y,winLeft.begin_x);
	return win;

}
WINDOW *createLeftTopWin()
{
	WINDOW * win = createWin(winLeftTop.nlines, winLeftTop.ncols,winLeftTop.begin_y,winLeftTop.begin_x);
	return win;

}
WINDOW *createLeftBottomWin()
{
	WINDOW * win = createWin(winLeftBottom.nlines, winLeftBottom.ncols,winLeftBottom.begin_y,winLeftBottom.begin_x);
	return win;

}
int scrAddWin(Screen *scr,Win * win ,LayOut loc)
{
	if(scr)
	{
		scr->wins[loc] = win;
		scr->winsCount++;
	}
	else
		return 0;
	return 1;
}
