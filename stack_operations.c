#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
* execute_line - Executes a line from the Monty bytecode file
* @line: Line to execute
* @stack: Double pointer to the stack
* @line_number: Line number of the current line
*/
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
instruction_t instructions[] = {
{"pall", pall},
{NULL, NULL}
};
char *opcode;
char *arg;
int i = 0;

opcode = strtok(line, " \n");
if (!opcode || opcode[0] == '#') /* Ignore comments */
return;

arg = strtok(NULL, " \n");

if (strcmp(opcode, "push") == 0) /* Handle push separately */
{
push(stack, line_number, arg);
return;
}

while (instructions[i].opcode)
{
if (strcmp(instructions[i].opcode, opcode) == 0)
{
instructions[i].f(stack, line_number); /* Call function for pall */
return;
}
i++;
}

fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}

/**
* push - Pushes an element to the stack
* @stack: Double pointer to the stack
* @line_number: Line number of the current line
* @arg: Argument to push
*/
void push(stack_t **stack, unsigned int line_number, const char *arg)
{
stack_t *new_node;
int value;

if (!arg || !isdigit(*arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(arg);
new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->next = *stack;
new_node->prev = NULL;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}

/**
* pall - Prints all the values on the stack
* @stack: Double pointer to the stack
* @line_number: Line number of the current line
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
