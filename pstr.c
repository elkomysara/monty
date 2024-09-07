#include "monty.h"

/**
* f_pstr - prints the string starting at the top of the stack
* @head: stack head
* @counter: line number (unused)
* @bus: bus structure containing argument info (unused)
* Return: no return
*/
void f_pstr(stack_t **head, unsigned int counter, bus_t *bus)
{
stack_t *h;
(void)counter;
(void)bus;

h = *head;
while (h)
{
if (h->n <= 0 || h->n > 127)
break;
printf("%c", h->n);
h = h->next;
}
printf("\n");
}
