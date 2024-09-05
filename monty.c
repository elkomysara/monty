#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* main - Entry point for Monty interpreter
* @argc: Number of arguments
* @argv: Argument vector
* Return: 0 on success, otherwise error
*/
int main(int argc, char **argv)
{
FILE *file;
char *line = NULL;
size_t len = 0;
unsigned int line_number = 0;
stack_t *stack = NULL;

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

while (fgets(line, len, file) != NULL)
{
line_number++;
execute_line(line, &stack, line_number);
}

free(line);
free_stack(stack);
fclose(file);
return (0);
}
