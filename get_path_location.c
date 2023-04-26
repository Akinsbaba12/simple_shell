#include "shell.h"

/**
* *get_path_location - function gets the full path location of a command.
* @command: character command to find.
* Return: path location
* Else: NULL - if the path was not found.
*/

char *get_path_location(char *command)
{
	char *pth, *pth_cp, *pth_tok, *file_pth;
	int cmd_len, dir_len;
	struct stat buff;

	pth = _getenv("PATH");
	if (pth)
	{
		pth_cp = _strdup(pth);
		cmd_len = _strlen(command);
		pth_tok = strtok(pth_cp, ":");

		while (pth_tok != NULL)
		{
			dir_len = _strlen(pth_tok);
			file_pth = malloc(cmd_len + dir_len + 2);
			_strcpy(file_pth, pth_tok);
			_strcat(file_pth, "/");
			_strcat(file_pth, command);
			_strcat(file_pth, "\0");

			if (stat(file_pth, &buff) == 0)
			{
				free(pth_cp);
				return (file_pth);
			}
			else
			{
				free(file_pth);
			pth_tok = strtok(NULL, ":");
			}
		}
		free(pth_cp);
		if (stat(command, &buff) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
