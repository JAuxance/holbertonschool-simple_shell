#include "shell.h"

/**
 * is_interactive - check if shell is running interactively
 *
 * Return: 1 if interactive, 0 otherwise
 */
int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * read_line_noninteractive - read input with getline for pipes
 * @buffer: buffer to store input
 * @size: size of buffer
 *
 * Return: 0 on success, -1 on EOF
 */
int read_line_noninteractive(char *buffer, size_t size)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (-1);
	}
	if (line[read - 1] == '\n')
		line[read - 1] = '\0';
	strncpy(buffer, line, size - 1);
	buffer[size - 1] = '\0';
	free(line);
	return (0);
}
