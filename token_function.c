#include "shell.h"

/**
 * command_tokens - Function splits user's command input into tokens
 * @cmd_input: pointer to inputted command
 * @file_check: size of file descriptor check 
 * Return: array of pointer to strings
 */

char **command_tokens(char *cmd_input, ssize_t file_check)
{
	const char *delimiter = " \n";
	char **argv = NULL;
	char *cmd_input_cpy = NULL, *tok = NULL;
	int tok_len, j, i = 0, tok_cnt = 0;

	/*Allocate memory for cmd_input_cpy*/
	cmd_input_cpy = malloc(sizeof(char) * (file_check + 1));
	if (cmd_input_cpy == NULL)
	{
		perror("Error: Cannot Allocate Memory");
		return (NULL);
	}

	/*Copy cmd_input to cmd_input_cpy*/
	_strcpy(cmd_input_cpy, cmd_input);

	/*Count the number of tokens*/
	tok = strtok(cmd_input_cpy, delimiter);
	while (tok)
	{
		tok_cnt++;
		tok = strtok(NULL, delimiter);
	}

	/*Allocate memory for argv*/
	argv = malloc(sizeof(char *) * (tok_cnt + 1));
	if (argv == NULL)
	{
		perror("Error: Cannot Allocate Memory");
		free(cmd_input_cpy);
		return (NULL);
	}

	/*Tokenize cmd_input_cpy and store tokens in argv*/
	tok = strtok(cmd_input, delimiter);
	for (i = 0; i < tok_cnt; i++)
	{
		tok_len = _strlen(tok);
		argv[i] = malloc(sizeof(char) * (tok_len + 1));
		if (argv[i] == NULL)
		{
			perror("Error: Cannot Allocate Memory");
			free(cmd_input_cpy);
			for (j = 0; j < i; j++)
				free(argv[j]);
			free(argv);
			return (NULL);
		}
		_strcpy(argv[i], tok);
		tok = strtok(NULL, delimiter);
	}
	argv[tok_cnt] = NULL;

	free(cmd_input_cpy);
	return (argv);
}
