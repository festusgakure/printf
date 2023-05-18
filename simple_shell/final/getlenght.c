#include "shell.h"

/**
 * getLength - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t getLength(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}
