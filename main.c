#include "monty.h"
exp batm = {NULL, NULL, NULL};
/**
 * main - Entry point
 * @ac: lenght of arguments pass to monty
 * @av: arguments used by monty
 * Return: EXIT SUCCESS if success, EXIT FAILURE if not
 */
int main(int ac, char *av[])
{
	size_t len = 32;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	batm.fil = fopen(av[1], "r");
	if (!batm.fil)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&batm.buf, &len, batm.fil)) != EOF)
	{
		line_number++;
		split(batm.buf, &stack, line_number);
	}
	fmonkey(stack);
	exit(EXIT_SUCCESS);
}
