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
    char *token;
    char *args[1024];
    pid_t pid;
    int is_interactive = isatty(STDIN_FILENO);
    int i;

    while (1)
    {
        if (is_interactive)
        {
            write(1, "$ ", 2);
        }
        read = getline(&buffer, &n, stdin);
        if (read == -1)
        {
            free(buffer);
            return (0);
        }
        if (buffer[read - 1] == '\n')
        {
            buffer[read - 1] = '\0';
        }

        /* extract first words*/
        i = 0;
        token = strtok(buffer, " ");
        if (token != NULL && i < 1023)
        {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if(args[0] == NULL)
        {
            continue;
        }
        {

        pid = fork();
        if (pid == 0)
        {
            
            execvp(args[0], args);
            perror(args[0]);
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
}
