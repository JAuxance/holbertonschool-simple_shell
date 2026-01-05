#include "main.h"
/**
 * execute_command - executes a command using fork and execve
 * @args: array of arguments for the command
 * Return: exit status of command or -1 on error
 */

int execute_command(char *args[])
{
	pid_t pid;
	int wstatus;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(args[0]);
		_exit(127);
	}

	if (waitpid(pid, &wstatus, 0) < 0)
	{
		perror("waitpid");
		return (1);
	}

	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));

	return (1);
}
