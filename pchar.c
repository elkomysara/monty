#include "monty.h"

/**
* f_pchar - prints the char at the top of the stack
* @head: stack head
* @counter: line number
* @bus: bus structure containing argument info
* Return: no return
*/
void f_pchar(stack_t **head, unsigned int counter, bus_t *bus)
{
stack_t *h;

h = *head;
if (!h)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
fclose(bus->file);
free(bus->content);
free_stack(*head);
exit(EXIT_FAILURE);
}
if (h->n < 0 || h->n > 127)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
fclose(bus->file);
free(bus->content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%c\n", h->n);
}
