#include "main.h"

/**
 * find_command_in_path - searches for a command in path directories
 * @command_name: the command name to search for
 * @envp: environment variables
 * Return: full path to command if found, NULL otherwise
 */
char *find_command_in_path(char *command_name, char **envp)
{
	char *path_env = NULL, *path_copy, *directory, *full_path; /* pointer on path value, PATH copy we can modify, directory extract from PATH */
	size_t path_length;										   /* length to allocate */
	int i;													   /* index in envp */

	if (command_name == NULL || command_name[0] == '\0')
		return (NULL);
	/* If commands contains '/', treat it as a path */
	if (strchr(command_name, '/') != NULL)
		return (access(command_name, X_OK) == 0 ? strdup(command_name) : 
			NULL);											  /* verify if the file exist and is executable */
	
	for (i = 0; envp[i] != NULL; i++)						  /* travel all environment variables */
		if (strncmp(envp[i], "PATH=", 5) == 0)				  /* compare only the five first caracteres */
		{
			path_env = envp[i] + 5;							  /* path_env point just aafter PATH */
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
		path_length = strlen(directory) + strlen(command_name) + 2; /* dir + "/" + cmd + "\0" */
		full_path = malloc(path_length);
		if (full_path == NULL)        /* full path len = directory + command len ex : /usr/local/bin/ls */
			return (free(path_copy), NULL);
		snprintf(full_path, path_length, "%s/%s", directory, command_name); /* fill full_path with directory and command_name */
		if (access(full_path, X_OK) == 0)									/* file exist and is executable ? */
			return (free(path_copy), full_path);							/* if yes, free path_copy and return full_path, if not pass at next directory */
		free(full_path);
		directory = strtok(NULL, ":");										/* pass at next directory of the path ex: local/bin/ls */
	}
	return (free(path_copy), NULL);
}
