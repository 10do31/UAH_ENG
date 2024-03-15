#
# ncurses-tutorial  Makefile
#

CC = gcc
CFLAGS = -g -Wall --pedantic -ansi
# CFLAGS = -g -Wall --pedantic -ansi --coverage

ncursesdemo: test1.c
	$(CC) $(CFLAGS) test1.c -o testdemo1 -l ncurses

clean:
	rm testdemo1 *.gcda *.gcno *.gcov
