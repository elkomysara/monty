#include "monty.h"

/**
* f_mod - computes the remainder of the division of the second
* top element of the stack by the top element of the stack.
* @head: stack head
* @counter: line number
* @bus: bus structure
* Return: no return
*/
void f_mod(stack_t **head, unsigned int counter, bus_t *bus)
{
stack_t *temp;
int result;

(void)bus;
if (*head == NULL || (*head)->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
exit(EXIT_FAILURE);
}
if ((*head)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
exit(EXIT_FAILURE);
}
temp = *head;
result = temp->next->n % temp->n;
temp->next->n = result;
*head = temp->next;
free(temp);
}
