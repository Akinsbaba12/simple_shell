#include "shell.h"

/**
 * *find_command_path - function gets the full path of a command.
 * @command: character command to find.
 * Return: full path of the command
 * Else: NULL - if the command was not found.
 */

char *find_command_path(char *command)
{
	char *pth, *pth_cp, *pth_tok, *file_pth;
	size_t len;

	/*Check if the command is already a full path.*/
	if (_strchr(command, '/') != NULL)
	{
		/*The command is already a full path.*/
		return (_strdup(command));
	}
	/*Split the PATH environment variable into individual directories.*/
	pth = _getenv("PATH");
	if (pth == NULL)
	{
		/*The PATH environment variable is not set.*/
		return (NULL);
	}
	pth_cp = _strdup(pth);
	pth_tok = _strtok(pth_cp, ":");

	while (pth_tok != NULL)
	{
		/*Construct the full path of the command.*/
		len = _strlen(pth_tok) + _strlen(command) + 2;
		file_pth = malloc(len);
		write(STDOUT_FILENO, pth_tok, _strlen(command));

		/* Check if the file exists and is executable.*/
		if (access(file_pth, X_OK) == 0)
		{
			free(pth_cp);
			return (file_pth);
		}
		free(file_pth);
		pth_tok = _strtok(NULL, ":");
	}
	free(pth_cp);
	return (NULL);
}

/**
 * exec_command - Function executes a command on CLI
 * with the given arguments.
 * @argv:  Array of strings for the command and its arguments.
 *
 */

void exec_command(char **argv)
{
	char *command, *path;

	if (argv)
	{
		command = argv[0];

		/*Find the full path of the command.*/
		path = find_command_path(command);
		/* Eecute the command. */
		if (execve(path, argv, NULL) == -1)
		{
			perror("Error: No such file or directory");
		}
	}
}
