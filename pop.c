#include "monty.h"

/**
* f_pop - removes the top element of the stack
* @head: stack head
* @counter: line number
* @bus: unused
*
* Description: This function removes the top element from the stack.
* If the stack is empty, it prints an error message and exits with failure.
* Return: no return
*/
void f_pop(stack_t **head, unsigned int counter, bus_t *bus)
{
stack_t *temp;

(void)bus;
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
exit(EXIT_FAILURE);
}
temp = *head;
*head = (*head)->next;
if (*head)
(*head)->prev = NULL;
free(temp);
}
