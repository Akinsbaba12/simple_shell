#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void display_prompt(void);

char *_getenv(char *name);

int _strncmp(const char *str1, const char *str2, size_t num);

char *_strtok(char *str, const char *delim);

int _strcmp(char *s1, char *s2);

char *_strchr(const char *str, int ch);

char *_strdup(char *str);

char *_strcat(char *dest, char *src);

int _strlen(char *s);

char *_strcpy(char *dest, char *src);

/*void exec_command(char **argv);*/
void execmnd(char **argv);

/*char *find_command_path(char *command);*/
char *get_path_location(char *command);

#endif
