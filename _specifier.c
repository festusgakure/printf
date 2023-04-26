#include "main.h"

/**
 * _specifier - checks a character and assigns a function to print
 * @format: specifies the format
 *
 * Return: pointer to function
 */

int (*_specifier(const char *format))(va_list)
{
	int i;

	fn_comp arr[6] = {
		{"c", p_char},
		{"s", p_str},
		{"%", p_cent},
		{"i", p_int},
		{"d", p_dec},
		{"u", p_unsigned},
		{NULL, NULL}};

	for (i = 0; arr[i].comp != NULL; i++)
	{
		if (*(arr[i].comp) == *format)
		{
			return (arr[i].p);
		}
	}

	return (NULL);
}
