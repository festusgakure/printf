#include "main.h"
/**
 * p_unsigned - prints an unsigned integer
 * @args: variadic arguments
 *
 * Return: number of characters printed
 */
int p_unsigned(va_list args)
{
	int i = 0;
	int cntr = 0;
	unsigned int num;
	int arr[10];
	char x[1];

	num = va_arg(args, unsigned int);

	while (num != 0)
	{
		arr[i] = (num % 10);
		num = num / 10;
		if (num == 0)
		break;
		i++;
	}
	for (i = i; i >= 0; i--)
	{
		x[0] = ('0' + arr[i]);
		cntr += write(1, x, 1);
	}
	return (cntr);
}
