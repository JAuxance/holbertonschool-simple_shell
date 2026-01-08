#include "main.h"

/**
 * find_command_in_path - searches for a command in path directories
 * @command_name: the command name to search for
 * @envp: environment variables
 * Return: full path to command if found, NULL otherwise
 */
char *find_command_in_path(char *command_name, char **envp)
{
	/* pointer on path value, PATH copy, directory extract from PATH */
	char *path_env = NULL, *path_copy, *directory, *full_path;
	size_t path_length;										   /* length to allocate */
	int i;													   /* index in envp */

	if (command_name == NULL || command_name[0] == '\0')
		return (NULL);
	/* If commands contains '/', treat it as a path */
	if (strchr(command_name, '/') != NULL)
		/* verify if the file exist and is executable */
		return (access(command_name, X_OK) == 0 ? strdup(command_name) : NULL);
	for (i = 0; envp[i] != NULL; i++) /* travel all environment variables */
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5; /* path_env point just after PATH */
			break;
		}
	if (path_env == NULL || path_env[0] == '\0')
		return (NULL);
	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);
	directory = strtok(path_copy, ":"); /* cutting the PATH, at the ":"  */
	while (directory != NULL)
	{
		/* dir + "/" + cmd + "\0" */
		path_length = strlen(directory) + strlen(command_name) + 2;
		full_path = malloc(path_length);
		/* full path len = directory + command len ex : /usr/local/bin/ls */
		if (full_path == NULL)
			return (free(path_copy), NULL);
		/* fill full_path with directory and command_name */
		snprintf(full_path, path_length, "%s/%s", directory, command_name);
		/* file exist and is executable ? */
		if (access(full_path, X_OK) == 0)
			return (free(path_copy), full_path);
		free(full_path);
		directory = strtok(NULL, ":");
	}
	return (free(path_copy), NULL);
}
