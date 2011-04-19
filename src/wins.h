#ifndef __TETRIIS__H
#define __TETRIIS__H
#include <ncurses.h>
#define MAX_WIN_COUNT 128
typedef struct Window{
	int nlines;
	int ncols;
	int begin_y;
	int begin_x;

}Win;
typedef struct Screen{
	Win wins[MAX_WIN_COUNT];
	size_t winsCount;
}Screen;
enum LayOut{
	RIGHT = 0,
	LEFT = 1,
	LEFT_TOP = 2,
	LEFT_BOTTOM = 3
};
int scrAddWin(Screen *scr, Win *win);
WINDOW *createWin(int nlines, int ncols,int begin_y,int begin_x);
WINDOW *createRightWin();
WINDOW *createLeftWin();
WINDOW *createLeftTopWin();
WINDOW *createLeftBottomWin();

void initScreen();
void destroyScreen();
#endif
