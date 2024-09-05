#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: pointer to monty file
* @bus: pointer to bus structure
* @content: line content to be parsed and executed
*
* Description: This function processes the content from the Monty bytecode
* file line by line, identifying and executing the appropriate opcode.
* It utilizes a bus structure to manage state and handles errors if
* an unknown instruction is encountered.
*
* Return: 0 on success, or exits with failure if an error occurs
*/

int execute(char *content, stack_t **stack,
unsigned int counter, FILE *file, bus_t *bus)
{
instruction_t opst[] = {
{"push", f_push}, {"pall", f_pall},
{NULL, NULL}
};
unsigned int i = 0;
char *op;

op = strtok(content, " \n\t");
if (op && op[0] == '#')
return (0);
bus->arg = strtok(NULL, " \n\t");

while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
opst[i].f(stack, counter, bus);
return (0);
}
i++;
}

if (op && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
