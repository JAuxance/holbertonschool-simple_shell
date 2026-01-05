#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

int read_and_pars(char **buffer, size_t *n, char *args[], int *is_interactive);
int execute_command(char *args[]);

/*int main(int ac, char **av);*/
#endif /* MAIN.H */
