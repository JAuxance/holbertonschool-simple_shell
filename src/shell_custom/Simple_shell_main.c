#include "shell.h"

/**
 * main - entry point for simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char buffer[BUFFER_SIZE];
	int ret, interactive;

	interactive = is_interactive();
	if (interactive)
		init_curses();

	while (1)
	{
		if (interactive)
			ret = prompt_input(buffer, sizeof(buffer));
		else
			ret = read_line_noninteractive(buffer, sizeof(buffer));

		if (ret == -1)
			break;
		if (strcmp(buffer, "exit") == 0 || strcmp(buffer, "!kill") == 0)
			break;

		if (interactive)
		{
			printw("\nCommande inconnue : %s\n", buffer);
			printw("Appuie sur une touche...");
			refresh();
			getch();
			clear();
		}
		else
		{
			printf("Commande inconnue : %s\n", buffer);
		}
	}

	if (interactive)
		cleanup_curses();
	return (0);
}
