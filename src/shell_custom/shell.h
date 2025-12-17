#ifndef SHELL_H
#define SHELL_H

#include <ncurses.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

/* curses_utils.c */
void init_curses(void);
void cleanup_curses(void);

/* input_handler.c */
int handle_backspace(char *buffer, int *i, int start_x);
int prompt_input(char *buffer, size_t size);

/* mode_detector.c */
int is_interactive(void);
int read_line_noninteractive(char *buffer, size_t size);

#endif
