#include "main.h"
/**
 * read_and_parse - reads a line from stdin and parses it into arguments
 * @buffer: pointer to the buffer to store the input line
 * @n: pointer to the size of the buffer
 * @args: array to store the parsed arguments
 * @is_interactive: flag indicating if the shell is in interactive mode
 * Return: -1 on EOF, 0 on error, 1 on success
 */

int read_and_parse(char *buffer, size_t n, char args[], int is_interactive)
{
	ssize_t read;

	if (is_interactive)
		write(STDOUT_FILENO, "$ ", 2);

	read = getline(buffer, n, stdin);
	if (read == -1)
		return (-1);
	/*EOF(Ctrl + D)*/

	/*remove trailing newline*/
	if (read > 0 && (buffer)[read - 1] == '\n')
		(buffer)[read - 1] = '\0';

	/*empty line*/
	if ((buffer)[0] == '\0')
	{
		args[0] = NULL;
		return (1);
	}

	/*Subject says: one word, no arguments*/

	args[0] = buffer;
	args[1] = NULL;

	return (1);
}
