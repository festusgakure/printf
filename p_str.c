#include "main.h"

/**
 * p_str - prints  string  to stdout
 * @args: variadic arguments
 * Return: number of characters printed
 */

int p_str(va_list args)
{
	int i;
	int cntr = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);

	while (str[i])
	{
		cntr = write(1, &str[i], 1);
		i = i + 1;
	}

	return (cntr);
}
