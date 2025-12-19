#include "main.h"
/**
 * main - entry point for the shell
 *
 * Return: 0 on success
 */

int main(void)
{
	size_t n = 0;
	char *buffer = NULL;
	ssize_t read;
	char *command;

	while (1)
	{
		write(1, "$ ", 2);
		read = getline(&buffer, &n, stdin);
		if (read == -1)
		{
			printf("Exit\n");
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

		write(1, command, strlen(command));
		write(1, "\n", 1);
	}

	free(buffer);
	return (0);
}
/*
 2 ) Si un exécutable ne peut pas être trouvé, afficher un message d'erreur et afficher à nouveau l'invite.
(Non ; le code n'essaie pas d'exécuter des commandes ou de vérifier les exécutables — il se contente de répéter l'entrée.)

3 ) Gérer les erreurs.
(Partiellement ; il gère EOF mais ne gère pas les erreurs d'exécution, car il n'exécute pas de commandes.)
*/
       /* Ici, ajoute le code pour exécuter la commande avec fork et execvp */
        // Par exemple :
        pid_t pid = fork();
        if (pid == 0) {
            char *args[] = {command, NULL};
            execvp(command, args);
            perror(command);
            exit(1);
        } else {
            wait(NULL);
        }
    }

