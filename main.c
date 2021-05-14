#include "monty.h"
exp macr = {NULL, NULL, NULL};
/**
 * main - Main
 * @ac: length of arguments
 * @av: arguments used
 * Return: EXIT SUCCES OR FAILURE
 */
int main(int ac, char *av[])
{
	size_t len = 32;
	ssize_t read;
	unsigned int i = 0;
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monti file\n", 18);
		exit(EXIT_FAILURE);
	}
	macr.fil = fopen(av[1], "r");
	if (!macr.fil)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&macr.buf, &len, macr.fil)) != EOF)
	{
		i++;
		tokenize(macr.buf, &stack, i);
	}
	freeList(stack);
	exit(EXIT_SUCCESS);
}

/**
 * freeList - free a list.
 * @stack: doubly linked list.
 * Return: void.
 */

void freeList(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	fclose(macr.fil);
	free(macr.buf);
}
