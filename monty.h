#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>

typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void execute_line(char *line, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number, const char *arg);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

#endif /* MONTY_H */
