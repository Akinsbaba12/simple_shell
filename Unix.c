#include "shell.h"

/**
* main - a program that displays a prompt on the screen
*        and  allows user to input a comand.
* @argc: an integer that represents the number of command-line arguments
*        passed to the program.
* @argv: a pointer to an array of strings that contains the command-line
*        arguments passed to the program.
* Return: 0 - if it succesfully prints the inputted commad.
*/

int main(int argc, char **argv)
{

char *print_prompt = "simple_shell ? ";
 char *CLI_ptr = NULL, *CLI_ptr_copy = NULL;
 size_t x = 0;
 ssize_t tot_chars_read;
 const char *delm = " \n";
 int cnt_tok = 0;
 char *tok;
 int a;


 (void)argc;



while(1)
{
write(STDOUT_FILENO, print_prompt,_strlen (print_prompt));
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
		       _strcpy(CLI_ptr_copy, CLI_ptr);

		       tok = strtok(CLI_ptr, delm);

		       while (tok != NULL)
			 {
			   cnt_tok++;
			   tok = strtok(NULL, delm);
			 }
		       cnt_tok++;

		       argv = malloc(sizeof(char *) * cnt_tok);

		       tok = strtok(CLI_ptr_copy, delm);

		       for (a = 0; tok != NULL; a++)

		       {
			 argv[a] = malloc(sizeof(char) * _strlen(tok));
			 _strcpy(argv[a], tok);

			   tok = strtok(NULL, delm);
		       }
		       argv[a] = NULL;

		       execmnd(argv);
		       //exec_command(argv);

}
free(CLI_ptr);
 free(CLI_ptr_copy);
return (0);
}
