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
	char *buffer = NULL;
	char *args[1024];
	int is_interactive = isatty(STDIN_FILENO);

	while (1) /* loop works */
	{
		if (!read_and_parse(&buffer, &n, args, is_interactive))
		{
			free(buffer); /* if r_n_p == Null, free buffer and return 0*/
			return (0);
		}
		if (args[0] == NULL) /* if first value of array args is null continue*/
			continue;
		execute_command(args); /* execute command with args array */
	}
	free(buffer); /* free buffer before exiting */
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *args[] = {"/tmp/ls -l", NULL};

		execve("/bin/ls", args, NULL);
		perror("execve failed");
		exit(1);
	}
	else
		wait(NULL);
	pid = fork();
	if (pid == 0)
	{
	}
}
