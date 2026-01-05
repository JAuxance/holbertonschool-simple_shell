#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>


int read_and_parse(char **buffer, size_t *n, char *args[], int is_interactive);
int execute_command(char *args[]);
char *find_command_in_path(char *command);

extern char **environ;

/*int main(int ac, char **av);*/
#endif /* MAIN.H */
