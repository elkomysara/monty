#include "monty.h"
#include <ctype.h> /* Added this to declare isdigit function */

/**
* execute_line - Executes a single line of bytecode.
* @line: The line to execute.
* @stack: The stack to operate on.
* @line_number: The current line number in the file.
*
* Description: This function parses the bytecode line
* and executes the corresponding stack operations.
*/
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
/* Moved the declaration before code */
char *arg;

/* Temporary use of 'stack' to suppress warning until push is implemented */
(void)stack;

if (strncmp(line, "push", 4) == 0)
{
arg = strtok(line + 4, " \t\n");
if (!arg || !isdigit(*arg))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
/* int value = atoi(arg); // Commented out as it's not yet used */
/* Call push function here (to be implemented) */
}
else if (strcmp(line, "pall\n") == 0)
{
/* Call pall function here (to be implemented) */
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
exit(EXIT_FAILURE);
}
}

/**
* free_stack - Frees a stack.
* @stack: The stack to free.
*
* Description: This function frees the entire stack to
* release memory allocated for stack nodes.
*/
void free_stack(stack_t *stack)
{
stack_t *temp;
while (stack)
{
temp = stack->next;
free(stack);
stack = temp;
}
}
