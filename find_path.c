#include "main.h"

/**
* find_command_in_path - searches for a command in path directories
* @command: the command name to search for
* @envp: environment variables
* Return: full path to command if found, NULL otherwise
*/
char *find_command_in_path(char *command, char **envp)
{
    char *path_env;/* pointer on path value */
    char *path_copy;/*PATH copy we can modify*/
    char *dir; /*directory extract from PATH*/
    char *full_path;
    size_t len;/* lenght to allocate*/
    int i;/* index in envp*/

    if (command == NULL || *command == '\0')
        return NULL;

    /* If command contains '/', treat it as a path */
    if (strchr(command, '/') != NULL)
    {
        if (access(command, X_OK) == 0)/* verify if the file exist and is executable*/
            return strdup(command);
        return NULL;
    }

    path_env = NULL;
    for (i = 0; envp[i] != NULL; i++)/* travel all environment variables*/
    {
        if (strncmp(envp[i], "PATH=", 5) == 0)/*compare only the five first caracteres*/
        {
            path_env = envp[i] + 5;/*path_env point just after PATH*/
            break;
        }
    }

    if (path_env == NULL || *path_env == '\0')
        return NULL;

    path_copy = strdup(path_env);/*making a copy of path_env*/
    if (path_copy == NULL)
        return NULL;

    dir = strtok(path_copy, ":");/*cutting the PATH, at the ":" */
    while (dir != NULL)
    {
        len = strlen(dir) + 1 + strlen(command) + 1; /* dir + "/" + cmd + "\0" */
        full_path = malloc(len);
        if (full_path == NULL)/*full path len = directory + command  len ex: /usr/local/bin/ls*/
        {
            free(path_copy);
            return NULL;
        }

        snprintf(full_path, len, "%s/%s", dir, command);/*fill full_path with dir and command*/
        
        if (access(full_path, X_OK) == 0) /* file exist and is executable ? */
        {
            free(path_copy);
            return full_path; /* if yes, free path_copy and return full_path, if not pass at next dir*/
        }

        free(full_path);
        dir = strtok(NULL, ":");/* pass at next dir of the path ex :local/bin/ls*/
    }

    free(path_copy);
    return NULL;
}
