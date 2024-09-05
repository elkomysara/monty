#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - custom implementation of getline function
 * @lineptr: pointer to the buffer where the read line will be stored
 * @n: pointer to the size of the buffer
 * @stream: input file stream
 *
 * Description: Reads a line from the specified stream, dynamically
 * allocates or resizes the buffer as needed using malloc and realloc.
 * The function stops when a newline or EOF is encountered. It returns
 * the number of characters read or -1 if EOF is reached without reading
 * any characters.
 *
 * Return: number of characters read, or -1 on failure
 */


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
