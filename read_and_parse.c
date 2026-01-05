#include "main.h"
/**
 * read_and_parse - reads a line from standard input
 * @buffer: pointer to the buffer to store the input line
 * @n: pointer to the size of the buffer
 * @args: array to store the parsed arguments
 * @is_interactive: flag indicating if the shell is in interactive mode
 * Return: number of characters read, -1 on EOF, or 0 on error
 */

int read_and_parse(char **buffer, size_t *n, char *args[], int is_interactive)
{
	ssize_t nread;
	char *token;
	int i = 0;

	if (is_interactive)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	nread = getline(buffer, n, stdin);

	if (nread == -1)
	{
		return (-1); /* EOF */
	}

	if ((*buffer)[nread - 1] == '\n')
	{
		(*buffer)[nread - 1] = '\0';
	}

	token = strtok(*buffer, " \t");
	while (token != NULL && i < 1023)
	{
		args[i++] = token;
		token = strtok(NULL, " \t");
	}
	args[i] = NULL;

	return (args[0] == NULL ? 0 : 1);
}
