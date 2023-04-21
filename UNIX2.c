#include "shell.h"

/**
 * main - a program that takes two integer
 * @argc: an integer that represents the number of command-line arguments
 *        passed to the program.
 * @argv: a pointer to an array of strings that contains the command-line
 *        arguments passed to the program.
 * Return 0
 */

int main(int argc, char **argv)
{
    char *print_prompt = "simple_shell ? ";
    char *CLI_ptr;
    size_t x = 0;
    ssize_t tot_chars_read;

    (void)argc;
    (void)argv;

    while (1)
    {
      write(STDOUT_FILENO, print_prompt,_strlen (print_prompt));
      tot_chars_read = getline(&CLI_ptr, &x, stdin);

        if (tot_chars_read == -1)
        {
            write(STDOUT_FILENO, "Logging Out From simple shell ?.....\n", 39);
            return (-1);
        }

        write(STDOUT_FILENO, CLI_ptr, tot_chars_read);
    }
    free(CLI_ptr);
    return (0);
}