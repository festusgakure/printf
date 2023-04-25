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
	int i = 0, val = 0, cntr = 0;
	va_list args;
	int (*p)(va_list);

	va_start(args, format);

	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			val = write(1, &format[i], 1);
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
			break;
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
