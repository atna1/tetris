all:test_list win
test_list:test_list.c ../llist.h ../llist.c
	g++ -g -o test_list test_list.c ../llist.c
win:win.cpp
	g++ -g -o win win.cpp -lncurses
