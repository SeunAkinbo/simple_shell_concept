#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * _getenv - Gets the environment variable
 * @name: String argument of the key value to be checked
 * Return: The variable.
 */

char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char *token;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(environ[i], name) == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
	}
	return (NULL);
}


/**
 * main - Retrives value of environment variable
 * @ac - Argument Count
 * @av - Argument vector
 *
 * Return - Always 0
 */

int main(int ac, char **av)
{
	char *value;
	char *token;

	value = _getenv(av[1]);
	token = strtok(value, ":");

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}

	return (0);
}
