#include "shell.h"

/**
 * _strncmp - function compares the first @num character
 * of @str1 and @str2
 * @str1: pointer to first string character
 * @str2: pointer to second string character
 * @num: number of bytes to compare
 * Return: 1 - if @str1 > @str2
 * Else: -1
 */

int _strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;

	for (i = 0; i < num; ++i)
	{
		if (str1[i] != str2[i])
		{
			return ((str1[i] < str2[i]) ? -1 : 1);
		}
		else if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
 * _getenv - function returns an environment variable
 * @name: pointer to character variable
 * Return: path of environment variable
 * Else: NULL if variable does not exist
 */

char *_getenv(char *name)
{
	char *token, *value, *cpy;
	size_t i = 0;

	if (!name)
		exit(1);
	while (environ[i] != NULL)
	{
		cpy = _strdup(environ[i]);
		token = _strtok(cpy, "=");
		if (_strcmp(name, token) == 0)
		{
			token = _strtok(NULL, "=");
			value = malloc(sizeof(char) * _strlen(token) + 1);
			if (!value)
			{
				free(cpy);
				return (NULL);
			}
			_strcpy(value, token);
			free(cpy);
			break;
		}
		i++;
		free(cpy);
	}
	return (value);
}
