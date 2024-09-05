#include "monty.h"
#include <string.h>

/**
* execute_line - Executes a line of bytecode.
* @line: The current line to execute.
* @stack: Pointer to the head of the stack.
* @line_number: The current line number.
*/
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
char *opcode, *arg;
instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{NULL, NULL}
};
int i = 0;

opcode = strtok(line, " \n\t");
if (!opcode || opcode[0] == '#')
return;

if (strcmp(opcode, "push") == 0)
arg = strtok(NULL, " \n\t");
else
arg = NULL;

while (instructions[i].opcode)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
instructions[i].f(stack, line_number, arg);
return;
}
i++;
}

fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
