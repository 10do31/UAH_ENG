#
# ncurses-tutorial  Makefile
#

CC = gcc
CFLAGS = -g -Wall --pedantic -ansi
# CFLAGS = -g -Wall --pedantic -ansi --coverage

ncursesdemo: tutorial.c
	$(CC) $(CFLAGS) tutorial.c -o ncursesdemo -l ncurses

clean:
	rm ncursesdemo *.gcda *.gcno *.gcov
