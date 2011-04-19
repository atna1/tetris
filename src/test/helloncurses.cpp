#include <iostream>
#include <ncurses.h>
using namespace std;
int main(int argc, const char *argv[])
{
	initscr();
 	printw("Hello World");
	refresh();
	getch();
	endwin();

	return 0;
}
