#include "monty.h"
/**
 * split - generates tokens
 * @buf: buffer that keeps lines
 * @stack: Doubly linked list that makes the stack
 * @line_number: lines in the file
 *
 * Return: void
 */

void split(char *buf, stack_t **stack, unsigned int line_number)
{
	char *name, *temp;

	name = strtok(buf, " \n\t");
	temp = strtok(NULL, " \n\t");
	batm.data = temp;
	if (name && name[0] != '#')
		get_opcode(stack, line_number, name);
}
