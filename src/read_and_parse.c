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
	ssize_t nread; /* result of getline, number of caracteres or -1 */
	char *token;   /* used by strtok */
	int i = 0;	   /* index in args */

	if (is_interactive) /* If you're in a terminal, you display the prompt $ */
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	nread = getline(buffer, n, stdin);

	if (nread == -1)
	{
		return (-1); /* ctrl d = -1 (EOF  or error) */
	}
	/* If the last character is a newline character, you replace it with \0*/
	if ((*buffer)[nread - 1] == '\n')
	{ /* line is ready to tokenize*/
		(*buffer)[nread - 1] = '\0';
	}
	/* cut the string in token with " " & "/t" in separator(/t = tab)*/
	token = strtok(*buffer, " \t");
	while (token != NULL && i < 1023)
	{
		args[i++] = token;			 /* store token in args[i] and move forward*/
		token = strtok(NULL, " \t"); /* NULL = continue on the same string */
	}
	/* end args by NULL, needed to execve*/
	args[i] = NULL;
	/* if args = 0 return 0, nothing to do, 1 command ready and -1 EOF or error*/
	return (args[0] == NULL ? 0 : 1);
}
