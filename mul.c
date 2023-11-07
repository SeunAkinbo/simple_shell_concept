#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
	int i, mul = 1;

	printf("The argc is: %d\n", ac);
	printf("The argcv[]:\n");

	for (i = 0; av[i] != NULL; i++)
	{
		if (i == 0)
			printf("argv: %s\n", av[i]);
		else
		{
			mul *= atoi(av[i]);
			printf("argv: %s\n", av[i]);
		}
	}
	printf("The product is: %d\n", mul);
	return (0);
}
