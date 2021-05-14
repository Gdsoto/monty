#include "monty.h"

/**
 * op_add - function to add
 * @stack: doubly linked list.
 * @line_number: counter of the line.
 *
 * Return: EXIT_FAILURE if fail.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_sub - function to sub
 * @stack: doubly linked list.
 * @line_number: counter of the line.
 *
 * Return: EXIT_FAILURE if fail.
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_mul - function to mul.
 * @stack: doubly linked list.
 * @line_number: counter of the line.
 *
 * Return: EXIT_FAILURE if fail.
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_div - function to div
 * @stack: doubly linked list.
 * @line_number: counter of the line.
 *
 * Return: EXIT_FAILURE if fail.
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_mod - function to mod.
 * @stack: doubly linked list.
 * @line_number: counter of the line.
 *
 * Return: EXIT_FAILURE if fail.
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	op_pop(stack, line_number);
}
