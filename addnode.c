#include "monty.h"

/**
* addnode - add node to the head of the stack
* @head: pointer to the head of the stack
* @n: new value to add
* Return: no return
*/
void addnode(stack_t **head, int n)
{
stack_t *new_node = malloc(sizeof(stack_t));

if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;

if (*head)
(*head)->prev = new_node;

*head = new_node;
}
