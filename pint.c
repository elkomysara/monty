#include "monty.h"

/**
* f_pint - prints the value at the top of the stack
* @head: stack head
* @counter: line number
* @bus: unused
*
* Description: This function prints the value at the top of the stack.
* If the stack is empty, it prints an error message and exits with failure.
* Return: no return
*/
void f_pint(stack_t **head, unsigned int counter, bus_t *bus)
{
(void)bus;
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
