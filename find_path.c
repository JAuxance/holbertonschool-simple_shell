#include "main.h"

/**
* find_command_in_path - searches for a command in path directories
* @command: the command name to search for
* Return: full path to command if found, NULL otherwise
*/
char *find_command_in_path(char *command)
{
    char *path_env, *path_copy, *dir;
    char *full_path;
    size_t len;

    if (command == NULL || *command == '\0')
        return NULL;

    /* If command contains '/', treat it as a path */
    if (strchr(command, '/') != NULL)
    {
        if (access(command, X_OK) == 0)
            return strdup(command);
        return NULL;
    }

    path_env = getenv("PATH");
    if (path_env == NULL || *path_env == '\0')
        return NULL;

    path_copy = strdup(path_env);
    if (path_copy == NULL)
        return NULL;

    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        len = strlen(dir) + 1 + strlen(command) + 1; /* dir + "/" + cmd + "\0" */
        full_path = malloc(len);
        if (full_path == NULL)
        {
            free(path_copy);
            return NULL;
        }

        snprintf(full_path, len, "%s/%s", dir, command);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path; /* caller must free() */
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
