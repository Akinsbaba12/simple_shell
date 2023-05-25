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

	int name_len = _strlen(name);
	int a = 0;

	while (environ[a])
	{
		if (_strncmp(name, environ[a], name_len) == 0 && environ[a][name_len] == '=')
		{
			return (&environ[a][name_len + 1]);
		}
		a++;
	}

	return (NULL);
}

/**
 * exit_shell - function exits the commandline prompt
 * @argv_cmd: command argument entered
 * @exit_message: message displayed on exit
 * Return: NULL
 * Else: Exit the shell
 */

void exit_shell(char *argv_cmd[], char *exit_message)
{

	char *error_message = "Exiting Shell Failed";
	int exit_status;

	if (argv_cmd[1])
	{
		exit_status = _atoi(argv_cmd[1]);
		if (exit_status >= 0)
		{
			free(exit_message);
			free(argv_cmd);
			exit(exit_status);
		}
		else
		{
			display_error_message(argv_cmd, error_message);
		}
	}
	else
	{
		free(argv_cmd);
		free(exit_message);
		exit(0);
	}
}
