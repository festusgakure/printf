#include "main.h"

/**
 * p_dec - prints an integer to base 10
 * @args: variadic parameter
 *
 * Return:  characters printed on Success
 */

int p_dec(va_list args)
{
	int i = 0;
	int cntr = 0;
	int num;
	int arr[10];
	char y[1];

	num = va_arg(args, int);

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
		y[0] = ('0' + arr[i]);
		cntr + = write(1, y, 1);
	}

	return (cntr);
}
