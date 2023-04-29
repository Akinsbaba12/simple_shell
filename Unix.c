#include "shell.h"
/**
 * main - program that displays a prompt on the screen.
 * @argc: integer number of command-line arguments passed to the program.
 * @argv: pointer array of strings of C.L arguments passed to the program.
 * Return: 0 - if it succesfully prints the inputted commad.
 */
int main(int argc, char **argv)
{
	char *CLI_ptr = NULL, *CLI_ptr_copy = NULL, *tok;
	const char *delm = " \n";
	bool get_pip = false;
	int a, cnt_tok = 0;
	(void)argc;

	while (1 && !get_pip)
	{
		if (isatty(STDIN_FILENO) == 0)
			get_pip = true;

		display_prompt();

		_strcpy(CLI_ptr_copy, CLI_ptr);
		tok = _strtok(CLI_ptr, delm);
		while (tok != NULL)
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
		exec_command(argv);
	}
	free(CLI_ptr);
	free(CLI_ptr_copy);
	return (0);
}
