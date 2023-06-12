#include "shell.h"

/**
 * shell_prompt - function reads unix shell prompts and display inputs
 * @file_check: pointer to the getline input
 * Return: character to the prompt_input
 *     
 */

char *shell_prompt(ssize_t *file_check)
{
	char *dis_prompt = "(?) ";
	char *newline_pos, *prompt_input = NULL;

	if (isatty(STDIN_FILENO))
	{
		write(1, dis_prompt, _strlen(dis_prompt));
	}

	prompt_input = getline();

	if (prompt_input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}

	*file_check = _strlen(prompt_input);

	if (*file_check == -1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		free(prompt_input);
		exit(EXIT_SUCCESS);
	}

	if (*file_check == 0 && isatty(STDIN_FILENO))
	{
		free(prompt_input);
		return (prompt_input(file_check));
	}

	newline_pos = _strchr(prompt_input, '\n');

	if (newline_pos)
		newline_pos = '\0';

	return (prompt_input);
}