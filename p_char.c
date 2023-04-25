#include "main.h"

/**
 * p_char - prints a character
 * @args: variadic argument
 *
 * Return: number of characters printed
 */

int print_char(va_list args)
{
	char x = (char)va_arg(args, int);
	int cntr = 0;

	if (x)
	{
		count = write(1, &x, 1);
		return (cntr);
	}

	return (0);
}
