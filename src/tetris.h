#ifndef __TETRIIS__H
#define __TETRIIS__H
typedef Screen{
	WinList *wins;

	
}Screen;
typedef Window{
	int nlines;
	int ncols;
	int begin_y;
	int begin_x;

}Win;

int addWin(Screen *scr, Win *win);
#endif
