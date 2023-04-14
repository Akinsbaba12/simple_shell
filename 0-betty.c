#include "main.h"

/**
* main - Program prints names of project contributors
* @name1: pointer to input first contributor
* @name2: pointer to inpute second contributor
* @name1_len: string length of 1st contributor
* @name2_len: string length ot 2nd contributor
*
* Return: 0 (Success)
*/

int main(void)
{
char *name1, *name2;
int name1_len, name2_len;

write(1, "Enter length of name1: ", 23);
read(0, &name1_len, sizeof(int));
write(1, "Enter length of name2: ", 23);
read(0, &name2_len, sizeof(int));

name1 = (char *)malloc((name1_len + 1) * sizeof(char));
name2 = (char *)malloc((name2_len + 1) * sizeof(char));

write(1, "Enter name1: ", 13);
read(0, name1, name1_len);
name1[name1_len] = '\0';
write(1, "Enter name2: ", 13);
read(0, name2, name2_len);
name2[name2_len] = '\0';

write(1, "The contributors to this project work are: ", 43);
write(1, name1, name1_len);
write(1, " and ", 5);
write(1, name2, name2_len);
write(1, "\n", 1);

return (0);
}
