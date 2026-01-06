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
	size_t n = 0;
	char *buffer = NULL, *args[1024], *cmd_path;
	int is_interactive = isatty(STDIN_FILENO), r, last_exit_code = 0;

	(void)ac;
	(void)av;

	while (1)
	{
		r = read_and_parse(&buffer, &n, args, is_interactive);
		if (r == -1)
		{
			free(buffer);
			return (last_exit_code);
		}
		if (r == 0 || args[0] == NULL)
			continue;
	if (handle_builtins(args, buffer, last_exit_code, envp))
		continue;
	cmd_path = find_command_in_path(args[0], envp);
		if (cmd_path != NULL)
		{
			args[0] = cmd_path;
			last_exit_code = execute_command(args, envp);
			free(cmd_path);
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			last_exit_code = 127;
		}
	}
}
