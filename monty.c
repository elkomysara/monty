#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* main - Entry point of the Monty ByteCode interpreter.
* @argc: Argument count.
* @argv: Argument vector (list of arguments).
*
* Description: This function reads a Monty bytecode file
* and executes the instructions line by line.
* Return: 0 on success, EXIT_FAILURE on error.
*/
int main(int argc, char *argv[])
{
FILE *file;
char line[1024];
size_t len = 1024;
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

fclose(file);
free_stack(stack);
return (0); /* Added parentheses around return value */
}
