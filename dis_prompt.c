#include "shell.h"

/**
 * display_prompt - function displays a prompt for user command
 * Return: void
 */

int display_prompt(void)
{       size_t x = 0;
	ssize_t tot_chars_read;
	char *CLI_ptr = NULL, *CLI_ptr_copy = NULL;
	char *dis_prompt = "(?) ";

	write(STDERR_FILENO, dis_prompt, _strlen(dis_prompt));
	tot_chars_read = getline(&CLI_ptr, &x, stdin);
	if (tot_chars_read == -1)
	{
		write(STDOUT_FILENO, "Logging Out From simple shell ?.....\n", 39);
		return (-1);
	}
	CLI_ptr_copy = malloc(sizeof(char) * tot_chars_read);
	if (CLI_ptr_copy == NULL)
	{
		perror("ooops!!: memory allocation failed");
		return (-1);
	}
	free(CLI_ptr);
	free(CLI_ptr_copy);
	return (0);
}
