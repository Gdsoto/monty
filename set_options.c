#include "holberton.h"

/**
 * op_push - opcode push pushes an element to the stack
 * @stack: double linked list that makes the stack
 * @line: counter of lines
 *
 * Return: EXIT_FAILURE if failed
 */

void op_push(stack_t **stack, unsigned int line)
{
	stack_t  *new_node, *temp;
	int i, j = 1, num;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ fprintf(stderr, "USAGE: monti file\n");
		freeList(new_node);
		exit(EXIT_FAILURE); }
	if (macr.data)
	{
		for (i = 0; macr.data[i] != '\0'; i++)
		{
			if (macr.data[i] >= 48 && macr.data[i] <= 57)
				j = 0;
			else
				j = 1;
		}
		if (j == 0)
			num = atoi(macr.data);
		else
		{ fprintf(stderr, "L%u: usage: push integer\n",
				line);
			freeList((*stack));
			free(new_node);
			exit(EXIT_FAILURE); }
	}
	else
	{ fprintf(stderr, "L%u: usage: push integer\n", line);
		freeList((*stack));
		free(new_node);
		exit(EXIT_FAILURE); }
	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;
	temp = *stack;
	if (*stack != NULL)
		temp->prev = new_node;
	*stack = new_node;
}

/**
 * op_pall - opcode pall prints all the values on the stack
 * @stack: double linked list that makes the stack
 * @line: counter of lines
 *
 * Return: Nothing
 */
void op_pall(stack_t **stack, unsigned int line)
{
	stack_t *cp_stack;
	(void)line;

	cp_stack = *stack;
	for (; cp_stack; cp_stack = cp_stack->next)
		printf("%d\n", cp_stack->n);
}

/**
 * op_pop - opcode pop removes the top element of the stack
 * @stack: double linked list that makes the stack
 * @line: counter of lines
 *
 * Return: EXIT_FAILURE if failed
 */
void op_pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		freeList((*stack));
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(tmp);
	if (*stack)
		(*stack)->prev = NULL;
}

/**
 * op_pint - opcode pint prints the value at the top of the stack
 * @stack: double linked list that makes the stack
 * @line: counter of lines
 *
 * Return: EXIT_FAILURE if failed
 */
void op_pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		freeList((*stack));
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
