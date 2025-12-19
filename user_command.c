#include "main.h"
#include <unistd.h>

/**
 * main - entry point for the shell
 *
 * Return: 0 on success
 */
int main(void)
{
	size_t n = 0;
	char *buffer = NULL, *token;
	ssize_t read;
	char *args[1024];
	pid_t pid;
	int is_interactive = isatty(STDIN_FILENO), i;

	while (1)
	{
		if (is_interactive)
		{
			write(1, "$ ", 2);
		}
		read = getline(&buffer, &n, stdin);
		if (read == -1)
		{
			free(buffer);
			return (0);
		}
		if (buffer[read - 1] == '\n')
		{
			buffer[read - 1] = '\0';
		}
		i = 0;
		token = strtok(buffer, " ");
		while (token != NULL && i < 1023)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		if (args[0] == NULL)
		{
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execvp(args[0], args);
			perror(args[0]);
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	free(buffer);
	return (0);
}
