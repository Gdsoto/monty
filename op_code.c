#include "monty.h"

/**
 * op_push - opcode push pushes an element to the stack
 * @stack: double linked list that makes the stack
 * @line_number: counter of lines
 *
 * Return: EXIT_FAILURE if failed
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t  *new_node, *temp;
	int i, j = 1, num;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ fprintf(stderr, "USAGE: monty file\n");
		fmonkey(new_node);
		exit(EXIT_FAILURE); }
	if (batm.data)
	{
		for (i = 0; batm.data[i] != '\0'; i++)
		{
			if (batm.data[i] >= 48 && batm.data[i] <= 57)
				j = 0;
			else
				j = 1;
		}
		if (j == 0)
			num = atoi(batm.data);
		else
		{ fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			fmonkey((*stack));
			free(new_node);
			exit(EXIT_FAILURE); }
	}
	else
	{ fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fmonkey((*stack));
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
 * @line_number: counter of lines
 *
 * Return: Nothing
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cp_stack;
	(void)line_number;

	cp_stack = *stack;
	for (; cp_stack; cp_stack = cp_stack->next)
		printf("%d\n", cp_stack->n);
}

/**
 * op_pop - opcode pop removes the top element of the stack
 * @stack: double linked list that makes the stack
 * @line_number: counter of lines
 *
 * Return: EXIT_FAILURE if failed
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fmonkey((*stack));
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
 * @line_number: counter of lines
 *
 * Return: EXIT_FAILURE if failed
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
