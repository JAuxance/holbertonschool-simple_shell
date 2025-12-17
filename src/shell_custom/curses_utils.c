#include "shell.h"

/**
 * init_curses - initialize ncurses and terminal settings
 */
void init_curses(void)
{
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	set_escdelay(25);
	curs_set(1);
}

/**
 * cleanup_curses - restore terminal state
 */
void cleanup_curses(void)
{
	endwin();
}
