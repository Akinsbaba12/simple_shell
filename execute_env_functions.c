#include "shell.h"

/**
 * check_env - function checks and comapres
 * if string is a built-in environment variable.
 * @str: Pointer to string to check.
 * Return: 0 - if string is found
 * Else 1.
 */
int check_env(char *str)
{
	if (_strcmp(str, "env") == 0 || _strcmp(str, "setenv") == 0 ||
			_strcmp(str, "unsetenv") == 0 || _strcmp(str, "echo") == 0)
	{
		return (0);
	}
	return (1);
}
/**
 * execute_env - function executes found built-in function.
 * @args: pointer array of arguments.
 * Return: 0 - if success.
 */
int execute_env(char **args)
{
	if (_strcmp(args[0], "setenv") == 0)
	{	
		return (set_env(args[1], args[2], 1));
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		show_env();
		return (0);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1])
		{
			return (unset_env(args[1]));
		}
		else
		{
			write(2, "Error: Unsetenv Failed", 30);
		}
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		if (args[1])
		{
			return (_echo(args[1]));
		}
		else
		{
			write(2, "Error: Enter string to echo", 28);
		}
write(2, "\n", 2);
	}
	return (1);
}
