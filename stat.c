#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - accesses file information
 *
 * Retun: 0 n success
 */


int main(int ac, char **av)
{
	struct stat buff;
	unsigned int i;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;

	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &buff) == 0)
		{
			printf("FOUND\n");
		}
		else
		{
			printf("NOT FOUND\n");
		}
		i++;
	}
	return (0);
}
