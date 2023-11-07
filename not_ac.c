#include <stdio.h>
#include <stdlib.h>

/**
 * main - Outputs the argument vector to the stdout
 * ac: Integer argument count
 * av: String argument vector
 * Return: 0
 */

int main(int ac, char **av)
{
	printf("The argc is: %d\n", ac);
	printf("The argcv[]:\n");
	
	for (; *av != NULL; av++)
	{
		printf("argv: %s\n", *av);
	}
	return (0);
}
