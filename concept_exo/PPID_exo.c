#include "main.h"
/**
 * main - prints the parent process ID of the current process
 * Return: Always 0
 */
int main(void)
{
	FILE *f;
	int ppid;

	f = fopen("/proc/self/stat", "r");
	if (f == NULL)
		return (0);

	if (fscanf(f, "%*d %*s %*c %d", &ppid) != 1)
	{
		fclose(f);
		return (0);
	}

	printf("%d\n", ppid);
	fclose(f);
	return (0);
}
