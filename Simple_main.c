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
	char *buffer = NULL; /*allocated by getline*/
	char *args[1024]; /*array of pointers to store the parsed command (tokens)*/
	char *cmd_path; /*to store absolute path*/ 
	int is_interactive = isatty(STDIN_FILENO); /*1 if standard output, 0 if since file or pipe*/
	int r; /*will receive the return code from read_and_parse*/
	int last_exit_code = 0; /*exit code of the last programm executed*/

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
		if (r == 0 || args[0] == NULL) /*Ignore blank lines or no command and return to the top of the loop*/
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
		else /* if not found, print error message and exit code become 127*/
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			last_exit_code = 127;
		}
	}
}
