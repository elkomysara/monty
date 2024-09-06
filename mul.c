#include "monty.h"

/**
* f_mul - multiplies the second top element of the stack
* with the top element of the stack.
* @head: stack head
* @counter: line number
* @bus: bus structure
* Return: no return
*/
void f_mul(stack_t **head, unsigned int counter, bus_t *bus)
{
stack_t *temp;
int result;

(void)bus;
if (*head == NULL || (*head)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
exit(EXIT_FAILURE);
}
temp = *head;
result = temp->next->n * temp->n;
temp->next->n = result;
*head = temp->next;
free(temp);
}
