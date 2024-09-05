#include "monty.h"

/**
* main - Entry point for Monty interpreter
* @argc: Number of arguments
* @argv: Argument vector
* Return: 0 on success, otherwise error
*/
int main(int argc, char **argv)
{
char *content = NULL;
FILE *file;
size_t size = 0;
int read_line = 1;
stack_t *stack = NULL;
unsigned int counter = 0;
bus_t bus = {NULL, NULL, NULL, 0}; /* Local variable */

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
bus.file = file;
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while (read_line > 0)
{
content = NULL;
read_line = _getline(&content, &size, file); /* Use custom getline */
bus.content = content;
counter++;
if (read_line > 0)
{
execute(content, &stack, counter, file, &bus); /* Pass bus as argument */
}
free(content);
}
free_stack(stack);
fclose(file);
return (0);
}
