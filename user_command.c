#include "main.h"
/**
 * main - entry point for the shell
 *
 * Return: 0 on success
 */

/**
 * The above function initializes variables for reading input and executing commands in a C program.
 */
int main(void)
{
    size_t n = 0;
    char *buffer = NULL;
    ssize_t read;
    char *command;
    pid_t pid;
    int is_interactive = isatty(STDIN_FILENO);

    while (1)
    {
        if (is_interactive)
        {
            write(1, "$ ", 2);
        }
        (1, "$ ", 2);
        read = getline(&buffer, &n, stdin);
        if (read == -1)
        {
            free(buffer);
            return (1);
        }
        if (buffer[read - 1] == '\n')
        {
            buffer[read - 1] = '\0';
        }

        /* extract first words*/
        command = strtok(buffer, " ");
        if (command == NULL)
        {
            continue;
        }


        pid = fork();
        if (pid == 0)
        {
            char *args[2];
            args[0] = command;
            args[1] = NULL;
            execvp(command, args);
            perror(command);
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }

    free(buffer);
    return (0);
}
