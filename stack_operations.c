#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
* pint - prints the value at the top of the stack.
* @stack: pointer to the head of the stack.
* @line_number: the current line number in the script.
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}

/**
* execute_line - Executes a line of bytecode.
* @line: The current line to execute.
* @stack: Pointer to the head of the stack.
* @line_number: The current line number.
*/
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
char *opcode;
instruction_t instructions[] = {
{"pint", pint},
{NULL, NULL}
};
int i = 0;

opcode = strtok(line, " \n\t");
if (!opcode || opcode[0] == '#') /* Ignore comments or empty lines */
return;

while (instructions[i].opcode)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
instructions[i].f(stack, line_number);
return;
}
i++;
}

fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
