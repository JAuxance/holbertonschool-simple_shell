#include "shell.h"

/**
 * handle_backspace - handle backspace key press
 * @buffer: input buffer
 * @i: pointer to current position
 * @start_x: starting x position
 *
 * Return: 1 if handled, 0 otherwise
 */
int handle_backspace(char *buffer, int *i, int start_x)
{
	int y, x;

	getyx(stdscr, y, x);
	if (x > start_x && *i > 0)
	{
		(*i)--;
		buffer[*i] = '\0';
		mvdelch(y, x - 1);
		move(y, x - 1);
	}
	return (1);
}

/**
 * prompt_input - read a line interactively into buffer
 * @buffer: buffer to store input
 * @size: size of buffer
 *
 * Return: 0 on normal enter, -1 if Alt+e detected
 */
int prompt_input(char *buffer, size_t size)
{
	int ch, i = 0, start_x, next;

	if (buffer == NULL || size == 0)
		return (-1);
	memset(buffer, 0, size);
	printw("☾ - ");
	getyx(stdscr, start_x, start_x);
	refresh();
	while (1)
	{
		ch = getch();
		if (ch == '\n')
			break;
		if (ch == KEY_BACKSPACE || ch == 127 || ch == 8)
		{
			handle_backspace(buffer, &i, start_x);
			continue;
		}
		if (ch == 27)
		{
			next = getch();
			if (next == 'e')
				return (-1);
			ungetch(next);
			continue;
		}
		if (ch & 0x80)
			ch &= 0x7F;
		if (ch >= 32 && ch <= 126 && i < (int)size - 1)
		{
			buffer[i++] = (char)ch;
			addch(ch);
		}
	}
	buffer[i] = '\0';
	return (0);
}
