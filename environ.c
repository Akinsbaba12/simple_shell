#include "shell.h"

/*
setenv
*/

int set_env(char *name, char *value, int overwrite)
{
int result;

    if (name == NULL || value == NULL) {
        fprintf(stderr, "Error: Invalid arguments\n");
        return -1;
    }

    if (overwrite == 0 && getenv(name) != NULL)
     {
        return 0;
}

    result = setenv(name, value, 1);  
    if (result != 0) 
    {
        fprintf(stderr, "Error: Failed to set environment variable\n");
        return -1;
    }

    return 0;  
}

/*
unsetenv
*/

int unset_env(char *name) 
{
int i, index = -1;
size_t name_len;
    if (name == NULL) {
        fprintf(stderr, "Error: Invalid argument\n");
        return -1;
    }
    name_len = strlen(name);
    for (i = 0; environ[i] != NULL; i++) {
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=') {
            index = i;
            break;
        }
    }

    if (index == -1) {
        
        return 0;
    }

    
    for (i = index; environ[i] != NULL; i++) {
        environ[i] = environ[i + 1];
    }

    return 0;  
}

