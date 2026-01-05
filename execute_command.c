#include "main.h"
/**
 * execute_command - executes a command using fork and execvp
 * @args: array of arguments for the command
 * Return: 0 on success
 */

int execute_command(char *args[])
{
	pid_t pid; /* init PID */
	int status;

	pid = fork(); /* Duplicate Pid for creat an child*/
	if (pid < 0)
	{
		perror("Fork failed");
		return (-1);
	}
	else if (pid == 0) /* if fork return success*/
	{
		execvp(args[0], args); /* Execute command in new child*/
		/* if execvp fail print error*/
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": One arguments authorized \n", 29);
		exit(127); /* exit child creat by fork*/
	}
	else
	{
		waitpid(pid, &status, 0); /* waiting child is over */
	}
	return (0); /* return success */
}
