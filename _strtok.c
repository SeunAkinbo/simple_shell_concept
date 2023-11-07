#include <stdio.h>
#include <string.h>

/**
 * _strtok - A string tokenizer
 * @str: A char array of an input string
 * @sep: The delimiter (a char) to be checked in the tokenized string
 * Return: Void
 */

void _strtok(const char *str, char sep)
{
    int len = strlen(str);
    int start = 0;

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == sep || str[i] == '\0')
        {
            if (i > start)
            {
                printf("%.*s\n", i - start, str + start);
            }
            start = i + 1;
        }
    }
}

