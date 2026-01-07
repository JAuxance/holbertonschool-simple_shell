#include "main.h"
/**
 * main - simple shell main loop
 * @ac: argument count (unused)
 * @av: argument vector (unused)
 * @envp: environment variables
 * Return: last command exit code
 */
int main(int ac, char **av, char **envp)
{
	size_t n = 0; /*allocated buffer size (getline)*/
	char *buffer = NULL, *args[1024], *cmd_path;
	char *command_name = NULL;				   /*getline buf, tokens, cmd path*/
	int is_interactive = isatty(STDIN_FILENO); /* 1 if interactive */
	int r;									   /* return code */
	int last_exit_code = 0;					   /* last command exit code */

	(void)ac;
	(void)av;
	while (1)
	{
		r = read_and_parse(&buffer, &n, args, is_interactive);
		if (r == -1) /*if EOF or Error, exit and return exit code*/
		{
			free(buffer);
			return (last_exit_code);
		}
		/*Ignore blank lines or no command and return to the top of the loop*/
		if (r == 0 || args[0] == NULL)
			continue;
		if (handle_builtins(args, buffer, last_exit_code, envp))
			continue;
		command_name = args[0];
		/* Search for the full path of the command in PATH directories */
		cmd_path = find_command_in_path(command_name, envp);
		if (cmd_path != NULL)
		{
			/* Replace command name with full path "ls" -> "/bin/ls") */
			args[0] = cmd_path;
			last_exit_code = execute_command(args, envp);
			free(cmd_path);
		}
		else /* if not found, print error message and exit code become 127*/
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", command_name);
			last_exit_code = 127;
		}
	}
}
