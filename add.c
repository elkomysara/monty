#include "monty.h"

/**
* f_add - adds the top two elements of the stack.
* @head: stack head
* @counter: line number
* @bus: bus structure containing argument info
* Return: no return
*/
void f_add(stack_t **head, unsigned int counter, bus_t *bus)
{
stack_t *temp;
int sum;

if (*head == NULL || (*head)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", counter);
fclose(bus->file);
free(bus->content);
free_stack(*head);
exit(EXIT_FAILURE);
}

sum = (*head)->n + (*head)->next->n;
temp = *head;
*head = (*head)->next;
(*head)->n = sum;
free(temp);
}
