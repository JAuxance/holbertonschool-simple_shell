#include "main.h"

/**
 * find_command_in_path - searches for a command in path directories
 * @command_name: the command name to search for
 * @envp: environment variables
 * Return: full path to command if found, NULL otherwise
 */
char *find_command_in_path(char *command_name, char **envp)
{
	char *path_env = NULL, *path_copy, *directory, *full_path;
	size_t path_length;
	int i;

	if (command_name == NULL || command_name[0] == '\0')
		return (NULL);
	if (strchr(command_name, '/') != NULL)
		return (access(command_name, X_OK) == 0 ? strdup(command_name) :
			NULL);
	for (i = 0; envp[i] != NULL; i++)
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break;
		}
	if (path_env == NULL || path_env[0] == '\0')
		return (NULL);
	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);
	directory = strtok(path_copy, ":");
	while (directory != NULL)
	{
		path_length = strlen(directory) + strlen(command_name) + 2;
		full_path = malloc(path_length);
		if (full_path == NULL)
			return (free(path_copy), NULL);
		snprintf(full_path, path_length, "%s/%s", directory, command_name);
		if (access(full_path, X_OK) == 0)
			return (free(path_copy), full_path);
		free(full_path);
		directory = strtok(NULL, ":");
	}
	return (free(path_copy), NULL);
}
