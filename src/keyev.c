#include "keyev.h"


int evLoop()
{
	int c ;
	while((c = getch())>0)
	{
		switch (c){
			case KEY_UP:
				printw("up arraw\n");
				refresh();
				break;
			case KEY_DOWN:
				printw("down arraw\n");
				refresh();
				break;
			case KEY_LEFT:
				printw("left arraw\n");
				refresh();
				break;
			case KEY_RIGHT:
				printw("right arraw\n");
				refresh();
				break;
			case 0x20:
				printw("pause\n");
				refresh();
				break;
			default:break;

		}
	}
	return 0;
}
