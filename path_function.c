#include "shell.h"

/**
 * *find_command_path - the function gets the full path of a command.
 * @command: character command to find.
 * Return: full path of the command.
 * Else: NULL - if the command was not found.
 */

char *find_command_path(char *command)
{
	char *pth, *pth_cp, *pth_tok, *file_pth;
	int cmd_len, dir_len;
	struct stat buffer;

	pth = _getenv("PATH");
	if (pth)
	{
		pth_cp = _strdup(pth);
		cmd_len = _strlen(command);
		pth_tok = _strtok(pth_cp, ":");

		while (pth_tok)
		{
			dir_len = _strlen(pth_tok);
			file_pth = malloc(cmd_len + dir_len + 2);

			_strcpy(file_pth, pth_tok);
			_strcat(file_pth, "/");
			_strcat(file_pth, command);
			_strcat(file_pth, "\0");

			if (stat(file_pth, &buffer) == 0)
			{
				free(pth_cp);
				return (file_pth);

			}
			else
			{
				free(file_pth);
				pth_tok = _strtok(NULL, ":");
			}
		}
		free(pth_cp);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
	}
	return (NULL);
}
