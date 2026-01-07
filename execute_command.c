#include "main.h"
/**
 * execute_command - executes a command using fork and execve
 * @args: array of arguments for the command
 * @envp: environment variables
 * Return: exit status of command or 1 on error
 */

int execute_command(char *args[], char **envp)
{
	pid_t pid; 		/* process identifier (fork return value) */
	int wstatus;    /* filled by waitpid, contain exit code or signal */

	pid = fork(); 	/* duplicate the processus */
	if (pid < 0)  	/* pid < 0 error, fork dont work */
	{
		perror("fork");
		return (1);
	}

	if (pid == 0) /* we are in the child, we replace it */
	{
		execve(args[0], args, envp);  /* args[0] = /bin/ls, args = array of the command /bin/ls -l /tmp */
		perror(args[0]);			  /*args[0] = /bin/ls */
		_exit(127);					 
	}

	if (waitpid(pid, &wstatus, 0) < 0) /* parent wait pid end and how it end, exit code, signal */
	{
		perror("waitpid");			   /* print error message "waitpid: No child processes" */
		return (1);
	}

	if (WIFEXITED(wstatus))			   /* if child process ended normally, return the same exit code */
		return (WEXITSTATUS(wstatus));

	return (1);
}
