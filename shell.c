#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/**
 * main - Program executes the command ls -l /tmp
 * Return: 0
 */


int main(void)
{
	pid_t child_pid;
	int status;
	char *buff = NULL;
	char *token;
	size_t n = 0;
	char **argv;
	size_t argc, max_tokens = 1024;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		getline(&buff, &n, stdin);
		token = strtok(buff, "\t\n ");
		argc = 0;

		argv = malloc(sizeof(char *) * max_tokens);
		if (argv == NULL)
		{
			perror("Error: argv malloc");
			free(buff);
			return (1);
		}

		while (token != NULL)
		{
			argv[argc] = token;
			argc++;
			token = strtok(NULL, "\t\n ");
		}
		argv[argc] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: child pid");
			free(buff);
			free(argv);
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error: execve");
				free(buff);
				free(argv);
				return (1);
			}
		}
		else
			wait(&status);
	}
	free(buff);
	free(argv);

	return (0);

}

