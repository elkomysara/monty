#include <stdio.h>
#include <stdlib.h>

int _getline(char **lineptr, size_t *n, FILE *stream)
{
int count = 0;
int ch;

if (*lineptr == NULL)
{
*lineptr = malloc(128);
*n = 128;
}

while ((ch = fgetc(stream)) != EOF && ch != '\n')
{
if (count + 1 >= (int) *n)
{
*n += 128;
*lineptr = realloc(*lineptr, *n);
}
(*lineptr)[count++] = ch;
}

if (ch == EOF && count == 0)
return (-1);

(*lineptr)[count] = '\0';
return (count);
}
