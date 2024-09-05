#include "monty.h"

/**
* f_pall - prints all the values on the stack
* @head: pointer to the head of the stack
* @counter: unused
* @bus: unused
* Return: no return
*/
void f_pall(stack_t **head, unsigned int counter, bus_t *bus)
{
stack_t *h;
(void)counter;
(void)bus; /* Mark bus as unused */

h = *head;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
