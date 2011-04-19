#include <stdio.h>
#include <termios.h>
#include <ncurses.h>
#define CELL "\x18\x18"
#define NEXTLINE "\n"
#define SPACE "  "
#define SCREEN_WIDTH 16
#define SCREEN_HIGHT 32

//define state of every picture
//L
const char *L1[]={
	CELL CELL CELL NEXTLINE CELL,
	CELL NEXTLINE CELL NEXTLINE CELL CELL,
	SPACE SPACE CELL NEXTLINE CELL CELL CELL,
	CELL CELL NEXTLINE SPACE CELL NEXTLINE SPACE CELL
};
const char *L2[]={
	CELL CELL CELL NEXTLINE SPACE SPACE CELL,
	SPACE CELL NEXTLINE SPACE CELL NEXTLINE CELL CELL,
	CELL NEXTLINE CELL CELL CELL,
	CELL CELL NEXTLINE CELL NEXTLINE CELL
};
// T
const char *T[]={
	CELL CELL CELL NEXTLINE SPACE CELL NEXTLINE SPACE CELL,
	CELL NEXTLINE CELL CELL CELL NEXTLINE CELL,
	SPACE CELL NEXTLINE SPACE CELL NEXTLINE CELL CELL CELL,
	SPACE SPACE CELL NEXTLINE CELL CELL CELL NEXTLINE SPACE SPACE CELL,
};
//Z
const char * Z1[]={
	CELL CELL NEXTLINE SPACE CELL CELL,
	SPACE CELL NEXTLINE CELL CELL NEXTLINE CELL,
};
const char *Z2[]={
	SPACE CELL CELL NEXTLINE CELL CELL,
	CELL NEXTLINE CELL CELL NEXTLINE SPACE CELL
};
// I
const char *I[]={
	CELL CELL CELL CELL,
	SPACE CELL NEXTLINE SPACE CELL NEXTLINE SPACE CELL NEXTLINE SPACE CELL
};
//square
const char *S[]={//square
	CELL CELL NEXTLINE CELL CELL
};
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
int run()
{
	WINDOW *right,*left;
	initWin(right,left);
}
void readyToStart()
{
	run();
	int ch;
	while(0 < (ch=getch()))
	{
		if(ch == KEY_F(5))
		{
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
	destroyScreen();
	return 0;
}
