#include "shell.h"

/**
* execmnd - function executes execve command on CLI
* @argv: char argument passed for command
* Return: if success - command path location
* Else: if fallied - error message
*/

void execmnd(char **argv)
{
char *command = NULL;
char *exe_command = NULL;


if (argv)
{
command = argv[0];

exe_command = get_path_location(command);

if (execve(exe_command, argv, NULL) == -1)
{
perror("Error: Execute command failed");
}
}
}
