#include "main.h"
/**
 * read_and_pars - reads a line from stdin and parses it into arguments
 * @buffer: pointer to the buffer to store the input line
 * @n: pointer to the size of the buffer
 * @args: array to store the parsed arguments
 * @is_interactive: flag indicating if the shell is in interactive mode
 *
 * Return: -1 on EOF, 0 on read error, 1 on success
 */

int read_and_pars(char **buffer, size_t *n, char *args[], int *is_interactive)
{
	ssize_t read; /* init READ */
	char *token;  /* init TOKEN */
	int i;

	if (is_interactive)
	{
		write(1, "$ ", 2);
	}

	/*getline read the use input from stdin and store it in buffer */
	read = getline(buffer, n, stdin);
	if (read == -1) /* verify getline success*/
		return (-1); /* end of line leave programme*/

	if ((*buffer)[read - 1] == '\n') /* replace newline with null terminator */
	{
		(*buffer)[read - 1] = '\0';
	}

	i = 0; /* new index */

	token = strtok(*buffer, " "); /* parse first element in buffer*/
	while (token != NULL && i < 1023) /* parse rest of elements */
	{
		args[i++] = token; /* put token elemets in an arrays */
		token = strtok(NULL, " "); /* continue parsing */
	}
	args[i] = NULL; /* null terminate the args array */
	return (1); /* return success */
}
