#include "monty.h"

/**
* f_pall - prints the stack
* @head: stack head
* @counter: line number (not used)
* @bus: pointer to bus structure (not used)
* Return: no return
*/
void f_pall(stack_t **head, unsigned int counter, bus_t *bus)
{
stack_t *h;
(void)counter;
(void)bus;

h = *head;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
