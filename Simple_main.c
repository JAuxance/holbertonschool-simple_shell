#include "main.h"
/**
 * main - simple shell main loop
 * Return: 0 on success
 */

int main(void)
{
	size_t n = 0;
	char *buffer = NULL;
	char *args[1024];
	int is_interactive = isatty(STDIN_FILENO);
	int r;
	char *cmd_path;
	int last_exit_code = 0;

	while (1)
	{
		r = read_and_parse(&buffer, &n, args, is_interactive);
		if (r == -1) /* EOF (Ctrl+D)*/
		{
			free(buffer);
			return (last_exit_code);
		}
		/*If you decide read_and_pars can return 0 on error*/
		if (r == 0)
			continue;
		/*Skip empty lines*/
		if (args[0] == NULL)
			continue;
		if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "EXIT") == 0)
		{
			free(buffer);
			exit(last_exit_code);
		}
		cmd_path = find_command_in_path(args[0]);
		if (cmd_path != NULL)
		{
			args[0] = cmd_path;
			last_exit_code = execute_command(args);
			free(cmd_path);
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			last_exit_code = 127;
		}
	}
}
