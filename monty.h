#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct bus_s - carries values through the program
 * @arg: argument value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag to change stack <-> queue
 *
 * Description: structure to manage state throughout the program
 */
typedef struct bus_s
{
char *arg;
FILE *file;
char *content;
int lifi;
} bus_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number, bus_t *bus);
} instruction_t;

void f_push(stack_t **head, unsigned int counter, bus_t *bus);
void f_pall(stack_t **head, unsigned int counter, bus_t *bus);
void f_pop(stack_t **head, unsigned int counter, bus_t *bus);
void f_pint(stack_t **head, unsigned int counter, bus_t *bus);
void f_swap(stack_t **head, unsigned int counter, bus_t *bus);
void f_add(stack_t **head, unsigned int counter, bus_t *bus);
void f_nop(stack_t **head, unsigned int counter, bus_t *bus);
void f_sub(stack_t **head, unsigned int counter, bus_t *bus);
void f_div(stack_t **head, unsigned int counter, bus_t *bus);
void f_mod(stack_t **head, unsigned int counter, bus_t *bus);
void f_pchar(stack_t **head, unsigned int counter, bus_t *bus);


void free_stack(stack_t *head);
int execute(char *content, stack_t **stack,
unsigned int counter, FILE *file, bus_t *bus);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
int _getline(char **lineptr, size_t *n, FILE *stream);

#endif /* MONTY_H */
