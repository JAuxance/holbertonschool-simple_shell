#include "main.h"
/**
 * main - prints all arguments it receives
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	int i;
	*av = "salut";
	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s", av[i]);
	}
	return (0);
}
