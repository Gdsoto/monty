#include "monty.h"

/**
 * op_swap - opcode swap
 * @stack: doubly linked list that makes the stack
 * @line_number: Counter of lines in the file
 *
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * op_nop - opcode add adds the top two elements of the stack
 * @stack: doubly linked list that makes the stack
 * @line_number: Counter of lines in the file
 *
 * Return: void
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
