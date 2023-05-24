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
	size_t x = 0;
	char *dis_prompt = "(?) ";
	char *CLI_ptr = NULL, *CLI_ptr_copy = NULL, *tok;
	const char *delm = " \n";
	int a, exe_stat, cnt_tok = 0;
	int interactive = isatty(STDIN_FILENO);

	(void)argc;

	while (1)
	{
		if (interactive)
			write(STDERR_FILENO, dis_prompt, _strlen(dis_prompt));
		tot_chars_read = getline(&CLI_ptr, &x, stdin);
		if (tot_chars_read == -1)
		{
			write(STDOUT_FILENO, "Logging Out From simple shell (?) .....\n", 45);
			break;
		}
		CLI_ptr_copy = malloc(sizeof(char) * tot_chars_read);
		if (CLI_ptr_copy == NULL)
		{
			perror("ooops!!: memory allocation failed");
			return (-1);
		}

		_strcpy(CLI_ptr_copy, CLI_ptr);
		tok = _strtok(CLI_ptr, delm);
		while (tok)
		{
			cnt_tok++;
			tok = _strtok(NULL, delm);
		}
		cnt_tok++;
		argv = malloc(sizeof(char *) * cnt_tok);
		tok = _strtok(CLI_ptr_copy, delm);
		for (a = 0; tok != NULL; a++)
		{
			argv[a] = malloc(sizeof(char) * _strlen(tok));
			_strcpy(argv[a], tok);
			tok = _strtok(NULL, delm);
		}
		argv[a] = NULL;
		exe_stat = exec_command(argv);
		if (exe_stat == 1)
			display_error_message(argv, "File not found");
		for (a = 0; argv[a] != NULL; a++)
		  {
		    free(argv[a]);
		  }
		free(argv);
	}
	free(CLI_ptr);
	free(CLI_ptr_copy);
	return (0);
}
