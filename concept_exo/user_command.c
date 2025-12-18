#include "main.h"
/**
 * main - entry point for the shell
 *
 * Return: 0 on success
 */

int main(void)
{
	size_t n = 0;
	char *buffer = NULL;
	ssize_t read;

	while (1)
	{
		write(1, "$ ", 2);
		read = getline(&buffer, &n, stdin);
		if (read == -1)
		{
			printf("Exit\n");
			free(buffer);
			return (1);
		}
		write(1, buffer, read);
	}

	free(buffer);
	return (0);
}
