#include "shell.h"

/**
 * main - program takes an array of strings
 * @execmnd takes an array of strings.
 * @argv array name
 * @return void
 */

void execmnd(char **argv)
{

	char *command = NULL;
	char *exe_command = NULL;
	if (argv)
	{
		command = argv[0];
		exe_command = get_path_location(command);
		if (execve(exe_command, argv, NULL) == -1)
		{
			perror("Error: Execute command failed");
		}
	}
}
