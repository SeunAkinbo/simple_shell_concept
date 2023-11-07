#include <stdlib.h>
#include <stdio.h>

/**
 * main - Gets the input from stdin
 * Return: 0
 */

int main(void)
{
	size_t n = 0;
	char *buff = NULL;

	printf("$ ");
	getline(&buff, &n, stdin);
	printf("%s", buff);

	free(buff);
	return (0);
}
