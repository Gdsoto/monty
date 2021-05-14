#include "holberton.h"
/**
 * tokenize - generate tokens
 * @buf: buffer that keeps lines
 * @stack: Doubly linked list that makes the stack
 * @line: Counter of lines in the file
 *
 * Return: volined
 */

void tokenize(char *buf, stack_t **stack, unsigned int line)
{
	char *name, *temp;

	name = strtok(buf, " \n\t");
	temp = strtok(NULL, " \n\t");
	macr.data = temp;
	if (name && name[0] != '#')
		get_opcode(stack, line, name);
}
