#include "monty.h"

/**
 * _isdigit - it is a digit or not
 * @c: char to be check
 *
 * Return: 0 or 1
 */
int _isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
