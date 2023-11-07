#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * main - Program executes the command ls -l /tmp
 * Return: 0
 */

int main(void)
{
	pid_t child_pid;
	int status, i, num_p = 5;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *argev[] = {NULL};

	for (i = 0; i < num_p; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, argev) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
