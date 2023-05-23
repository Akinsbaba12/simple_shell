#include "shell.h"

/**
 * _putchar - function writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(2, &c, 1));
}

/**
 * display_error_message - Function prints an error message
 * to the standard error file
 * @argv: pointer array of program argument
 * @message: error message displayed
 */

void display_error_message(char *argv[], char *message)
{
	int i;
	char *program_name = _getenv("_");

	if (program_name != NULL)
	{
		for (i = 0; program_name[i] != '\0'; i++)
		{
			_putchar(program_name[i]);
		}
		_putchar(':');
		_putchar(' ');
		_putchar('1');
		_putchar(':');
		_putchar(' ');
		for (i = 0; argv[0][i] != '\0'; i++)
		{
			_putchar(argv[0][i]);
		}
		_putchar(':');
		_putchar(' ');
		for (i = 0; message[i] != '\0'; i++)
		{
			_putchar(message[i]);
		}
		_putchar('\n');
	}
}
