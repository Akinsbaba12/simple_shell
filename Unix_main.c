#include "shell.h"
/**
 * main - program that displays a prompt on the screen.
 * @argc: integer number of command-line arguments passed to the program.
 * @argv: pointer array of strings of C.L arguments passed to the program.
 * Return: 0 - if it succesfully prints the inputted commad.
 */
int main(int argc, char **argv)
{
	ssize_t tot_chars_read;
	char *CLI_ptr = NULL, *CLI_ptr_copy = NULL, *tok;
	const char *delm = " \n";
	int a, exe_stat, cnt_tok = 0;


	(void)argc;

	while (1)
	{
		CLI_ptr = shell_prompt(&tot_chars_read);
		CLI_ptr_copy = malloc(sizeof(char) * tot_chars_read);
		if (CLI_ptr_copy == NULL)
		{
			perror("ooops!!: memory allocation failed");
			return (-1);
		}
		_strcpy(CLI_ptr_copy, CLI_ptr);
		tok = strtok(CLI_ptr, delm);
		while (tok)
		{
			cnt_tok++;
			tok = strtok(NULL, delm);
		}
		cnt_tok++;
		argv = malloc(sizeof(char *) * cnt_tok);
		tok = strtok(CLI_ptr_copy, delm);
		for (a = 0; tok != NULL; a++)
		{
			argv[a] = malloc(sizeof(char) * _strlen(tok) + 1);
			_strcpy(argv[a], tok);
			tok = strtok(NULL, delm);
		}
		argv[a] = NULL;
		if (argv[0] == NULL)
		{
			continue;
		}
		if (_strcmp(argv[0], "exit") == 0)
		{
			free(CLI_ptr_copy);
			exit_shell(argv, exe_stat);
			free_array_strings(argv);
			break;
		}
		exe_stat = exec_command(argv);
		if (exe_stat == 1)
		{
			display_error_message(argv, "File not found");
		}
		if (execute_env(argv) != 0)
		{
			free(CLI_ptr_copy);
		}
		free_array_strings(argv);
		/*return (0)*/;
	}
	for (a = 0; argv[a] != NULL; a++)
	{
		free(argv[a]);
	}
	free(argv);
	free(CLI_ptr_copy);
	free(CLI_ptr);
	return (0);
}
