#include "shell.h"

/**
* _strcat - concatenates @src to @dest
* @src: the source string to append to @dest
* @dest: the destiation string to be concatenated upon
* Return:pointer to the resulting string
*/

char *_strcat(char *dest, char *src)

{
int index = 0, dest_len = 0;

while (dest[index++])
dest_len++;
for (index = 0; src[index]; index++)
dest[dest_len++] = src[index];
return (dest);
}

/**
* _strdup - function copys string to new memory space location
* @str: char string to copy
* Return: 0
*/

char *_strdup(char *str)

{

char *ptr;
int a, ret = 0;

if (str == NULL)

return (NULL);

a = 0;

while (str[a] != '\0')

a++;

ptr = malloc(sizeof(char) * (a + 1));

if (ptr == NULL)

return (NULL);

for (ret = 0; str[ret]; ret++)

ptr[ret] = str[ret];

return (ptr);

}

/**
* _strlen - checks the length of a string
* @s: string to check
* Return: int length of the string
*/

int _strlen(char *s)

{
int length = 0;

while (s[length])
length++;
return (length);
}

/**
* _strcpy - function copies the string pointed to by src
* @dest: char type string
* @src: char type string
* Description: Copy the string pointed to by pointer __src__ to
* the buffer pointed to by **dest**
* Return: Pointer to _dest_
*/

char *_strcpy(char *dest, char *src)

{
int a = -1;

do {
a++;
dest[a] = src[a];
} while (src[a] != '\0');

return (dest);
}
