#include "monty.h"

/**
 * fmonkey - free a list.
 * @stack: doubly linked list.
 * Return: void
 */

void fmonkey(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	fclose(batm.fil);
	free(batm.buf);
}
