#include "main.h"

/**
main - entry point for the shell
Return: 0 on success*/
int main(void)
{
	size_t n = 0;
	char *buffer = NULL;
	char *args[1024];
	int is_interactive = isatty(STDIN_FILENO);
	int r;

	while (1)
	{
		r = read_and_parse(&buffer, &n, args, is_interactive);

		if (r == -1) /* EOF (Ctrl+D)*/
		{
			free(buffer);
			return (0);
		}

		/*If you decide read_and_pars can return 0 on error*/
		if (r == 0)
			continue;
		/*Skip empty lines*/

		if (args[0] == NULL)
			continue;

		execute_command(args);
	}
}
