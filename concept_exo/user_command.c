#include "main.h"
/**
 * main - entry point for the shell
 *
 * Return: 0 on success
 */
int main(void)
{
	size_t n = 10;
	char *buffer = NULL;

	printf("$ - ");
	getline(&buffer, &n, stdin);
	return (0);
}
