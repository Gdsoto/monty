#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack 
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line);
} instruction_t;

/**
 * struct monty_val - take the data, buffer and file to export
 * @data: Tokenized data
 * @buf: buffer to getline
 * @fil: file descriptor to open and close
 *
 * Description: data, buffer and file to export
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct monty_val
{
	char *data;
	char *buf;
	FILE *fil;
} exp;

extern exp macr;

void tokenize(char *, stack_t **, unsigned int);
void op_push(stack_t **stack, unsigned int line);
void op_pall(stack_t **stack, unsigned int line);
void op_pop(stack_t **stack, unsigned int line);
void op_pint(stack_t **stack, unsigned int line);
void get_opcode(stack_t **, unsigned int, char *);
void freeList(stack_t *stack);

#endif /* MONTY_H */
