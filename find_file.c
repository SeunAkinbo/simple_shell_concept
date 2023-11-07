#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * check_command - Checks if the file exists
 * @comman: String argument
 * Return: Void
 */

void check_command(char *command)
{
	struct stat st;

	if (stat(command, &st) == 0)
		write(1, "FILE FOUND\n", 12);
	else
		write(1, "FILE DOES NOT EXIST\n", 22);
}


/**
 * main - Finds a file in a path
 *
 * Return: Always 0
 */

int main(void)
{
	char *buf = NULL;
	size_t n = 0;
	char *token;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		getline(&buf, &n, stdin);
		token = strtok(buf, "\t\n ");

		if (strcmp(token, "which") == 0)
		{
			token = strtok(NULL, "\t\n ");
			while (token)
			{
				check_command(token);
				token = strtok(NULL, "\t\n ");
			}
		}
		else
		{
			write(1, "INVALID COMMAND\n", 18);
		}
	}
	return (0);
}
