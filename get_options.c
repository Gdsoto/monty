#include "holberton.h"

/**
 * get_opcode - select the function to use.
 * @name: find the option
 * @stack: doubly linked list.
 * @line: line.
 *
 * Return: EXIT_FAILURE
 */

void get_opcode(stack_t **stack, unsigned int line, char *name)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"pint", op_pint},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, name) == 0)
		{
			ops[i].f(stack, line);
			break;
		}
		i++;
	}

	if (!ops[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line, name);
		freeLine((*stack));
		exit(EXIT_FAILURE);
	}

}
