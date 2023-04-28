#include "shell.h"

/**
 * display_prompt - function displays a prompt for user command
 * Return: void
 */

void display_prompt(void)
{
	char *dis_prompt = "(?) ";

	write(STDERR_FILENO, dis_prompt, _strlen(dis_prompt));
}
