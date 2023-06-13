#include "shell.h"

/**
 * exec_command - Function executes a command on CLI
 * with the given arguments.
 * @argv:  Array of strings for the command and its arguments.
 * Return: Executable file if found
 * Else: Error
 */

int exec_command(char *argv[])
{
	char *command, *new_command, *null_command;
	pid_t child_pid;
	int status;
	size_t new_command_len;

	if (argv == NULL || argv[0] == NULL)
	{
		return (1);
	}
	command = argv[0];
	new_command = find_command_path(command);
	if (new_command && access(new_command, X_OK) != -1)
	{
		new_command_len = _strlen(new_command);
		null_command = malloc(new_command_len + 1);
		if (null_command == NULL)
		{
			display_error_message(argv, "Memory Allocation Error:");
			return (1);
		}
		_strcpy(null_command, new_command);
		null_command[new_command_len] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			display_error_message(argv, "Fork Error:");
		}
		else if (child_pid == 0)
		{
			if (execve(null_command, argv, NULL) == -1)
			{
				display_error_message(argv, "Execve Error:");
			}
			exit(0);
		}
		else
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				display_error_message(argv, "Waitpid Error:");
			}
		}
		if (_strcmp(null_command, command) != 0)
			free(null_command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		return (status);
	}
	/*free(null_command);*/
	return (1);
}
