#include "monty.h"

/**
 * get_opcode - funtion to look for the code to be used.
 * @name: option to find
 * @stack: doubly linked list.
 * @line_number: counter the line.
 *
 * Return: EXIT_FAILURE if fail..
 */

void get_opcode(stack_t **stack, unsigned int line_number, char *name)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"pint", op_pint},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, name) == 0)
		{
			ops[i].f(stack, line_number);
			break;
		}
		i++;
	}

	if (!ops[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, name);
		fmonkey((*stack));
		exit(EXIT_FAILURE);
	}

}
