#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - prints  a formatted srting
 * @format: prints (char *)
 * @...: variadic arguments
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int cntr = 0;
	int val = 0;
	va_list args;
	va_start(args, format);
	int (*p)(va_list);

	if (format == NULL)
		return (-1);

	while (format[i])
	{	
		if (format[i] != '%')
		{
			val = write(1,&format[i],1);
			cntr = cntr + val;
			i++;
			continue;
		}

		if (format[i] == '%')
		{
			p = _specifier(&format[i + 1]);
			if (p != NULL)
			{
				val = p(args);
				cntr = cntr + val;
				i = i + 2;
				continue;
			}

			if (format[i + 1] == '\0')
			{
				break;
			}

			if (format[i + 1] != '\0')
			{
				val = write(1, &format[i + 1], 1);
				cntr = cntr + val;
                        	i = i + 2;
                        	continue;
			}


		}
	}

	return (cntr);
}
