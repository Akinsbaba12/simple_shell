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
 * exit_shell - function exits the command line prompt
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

/**
 * create_variable - creates an environment variable
 * @env_name: name of the variable
 * @env_value: value of the variable
 *
 * Return: the new variable
 */

char *create_env(char *env_name, char *env_value)
{
	char *var = NULL, *new_var = NULL;

	new_var = _strcat(env_name, "=");
	if (new_var == NULL)
		return (NULL);

	var = _strcat(new_var, env_value);
	if (var == NULL)
	{
		free(new_var);
		return (NULL);
	}
	free(new_var);
	return (var);
}

/**
 * _echo - Functions executes echo command
 * @args: Argument variable pointer
 * return: 1 - if succesful
 * Else: -1
 **/

int _echo(char *args) 
{
	char *value;

	if (args == NULL) 
	{
		write(2, "Error: Enter string to echo", 30);
		return (-1);
	}

	value = _getenv(args);
	if (value) 
	{
		write(1, value, _strlen(value));
		write(1, "\n", 1);
	} 
	else 
	{
		write(1, "(?) \n", 5);
	}
	return (1);
}
