#include "main.h"
/**
 * handle_builtins - handles built-in commands
 * @args: array of arguments
 * @buffer: input buffer to free on exit
 * @exit_code: last command exit code
 * @envp: environment variables
 * Return: 1 if builtin was executed, 0 otherwise
 */
int handle_builtins(char **args, char *buffer, int exit_code, char **envp)
{
	int i;

	if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "EXIT") == 0)
	{
		/*compare the command with exit or EXIT, if yes free buffer and exit shell*/
		free(buffer);
		exit(exit_code);
	}
	/*if command = env, loop on all env variables, print one by line*/
	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; envp[i] != NULL; i++)
			printf("%s\n", envp[i]);
		return (1);
	}
	return (0);
}
