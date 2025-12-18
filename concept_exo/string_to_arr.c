#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * main - point d'entrée pour la conversion chaîne vers tableau
 *
 * Return: 0 en cas de succès
 */
int main(void)
{
    char *str = "Hello im my";
    char **array = NULL;
    int i = 0;
    int count = 0;
    char *str_copy = strdup(str);
    char *piece;

    if (!str_copy)
        return (1);

    // Compter les mots
    piece = strtok(str_copy, " ");
    while (piece != NULL)
    {
        count++;
        piece = strtok(NULL, " ");
    }
    array = malloc((count + 1) * sizeof(char *));
    if (!array)
    {
        free(str_copy);
        return (1);
    }

    free(str_copy);
    str_copy = strdup(str);
    if (!str_copy)
    {
        free(array);
        return (1);
    }

    piece = strtok(str_copy, " ");
    i = 0;
    while (piece != NULL)
    {
        array[i] = piece;
        i++;
        piece = strtok(NULL, " ");
    }
    array[i] = NULL;

    i = 0;
    while (array[i] != NULL)
    {
        printf("%s\n", array[i]);
        i++;
    }

    free(str_copy);
    free(array);
    return (0);
}
