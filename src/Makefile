all:tetris
tetris:tetris.c wins.h wins.c tetris.h keyev.h keyev.c
	gcc -Wall -g -o tetris tetris.c wins.c keyev.c -lncurses
clean:
	rm tetris
