#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main (int ac, char **av, char **env)
{
	printf("%p\n%p\n", env, environ);
	return (0);
}
