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

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while (read_line > 0)
{
content = NULL;
read_line = _getline(&content, &size, file); /* Use custom getline */
counter++;
if (read_line > 0)
{
execute(content, &stack, counter, file); /* No need for bus */
}
free(content);
}
free_stack(stack);
fclose(file);
return (0);
}
