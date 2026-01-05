#include "main.h"
/**
 * execute_command - executes a command using fork and execvp
 * @args: array of arguments for the command
 * Return: 0 on success
 */

int execute_command(char *args[])
{
	pid_t pid; /* init PID */

	pid = fork(); /* Duplicate Pid for creat an child*/
	if (pid == 0) /* if fork return success*/
	{
		execvp(args[0], args); /* Execute command in new child*/
		perror(args[0]);	   /* if execvp fail print error*/
		exit(1);			   /* exit child creat by fork*/
	}
	else
	{
		wait(NULL); /* waiting child is over */
	}
	return (0); /* return success */
}
