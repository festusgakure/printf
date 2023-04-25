#include "main.h"

/**
 * p_cent - prints %
 * @args: variadic argument
 * Return: number of characters printed
 */

int p_cent(va_list args)
{
	(void)args;

	write(1, "%", 1);

	return (1);
}
