#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 *
 *
 *
 *
 */


int main(void)
{
	char *str;
	char *strcp, *token;
	char sep[4] = " ";
	int len;

	str = "I am exploring basic shell creation";
	len = strlen(str);
	strcp = malloc(sizeof(char) * len);

	strcpy(strcp, str);
	token = strtok(strcp, sep);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, sep);
	}

	return (0);
	free(strcp);

}
