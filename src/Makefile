all:tetris
tetris:tetris.c wins.h wins.c tetris.h keyev.h keyev.c llist.h llist.c
	gcc -Wall -g -o tetris tetris.c wins.c keyev.c llist.c -lncurses
clean:
	rm tetris
