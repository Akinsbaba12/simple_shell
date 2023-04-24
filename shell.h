#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *_strdup(char *str);

char *_strcat(char *dest, char *src);

int _strlen(char *s);

char *_strcpy(char *dest, char *src);

void execmnd(char **argv);

char *get_path_location(char *command);
#endif

