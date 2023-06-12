#include "shell.h"

/**
 * main - program executes the Unix shell command line.
 * @argc: integer of argument count.
 * @argv: array pointer to strings of C.L arguments.
 * Return: 0.
 */

int main(int argc, char *argv[])
{
	char *unix_input;
	ssize_t fd_check;
	int exe_stat = 0;
	char **unix_argv;

	(void)argc;
	(void)argv;

	while (1)
	{
		unix_input = NULL;
		fd_check = 0;

		unix_input = shell_prompt(&fd_check);
		unix_argv = command_tokens(unix_input, fd_check);

		if (unix_input == -1)
		{
			write(STDOUT_FILENO, "Logging Out From simple shell (?) .....\n", 45);
			break;
		}

		if (unix_argv[0] == NULL)
		{
			free(unix_input);
			free_array_strings(unix_argv);
			continue;
		}

		if (_strcmp(unix_argv[0], "exit") == 0)
		{
			free(unix_input);
			exit_shell(unix_argv, exe_stat);
			free_array_strings(unix_argv);
			continue;
		}

		if (execute_env(unix_argv) != 0)
		{
			free(unix_input);
			free_array_strings(unix_argv);
			continue;
		}

		exe_stat = exec_command(argv);
		if (exe_stat == 1)
		{
			display_error_message(argv, "File not found");
		}

		free(unix_input);
		free_array_strings(unix_argv);
	}
	return (0);
}
