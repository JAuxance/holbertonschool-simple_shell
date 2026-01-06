#include "main.h"
/**
 * handle_builtins - handles built-in commands
 * @args: array of arguments
 * @buffer: input buffer to free on exit
 * @exit_code: last command exit code
 * Return: 1 if builtin was executed, 0 otherwise
 */
int handle_builtins(char **args, char *buffer, int exit_code)
{
	int i;

	if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "EXIT") == 0)
	{
		free(buffer);
		exit(exit_code);
	}
	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		return (1);
	}
	return (0);
}
