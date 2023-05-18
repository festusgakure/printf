#include <stdio.h>

/**
 * add - function to add two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: sum of the two integers
 */
void add(int a, int b)
{
	printf("the sum is %d\n", a + b);
}

/**
 * sub - function to subtract two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: difference between the two integers
 */
void sub(int a, int b)
{
	printf("the difference of %d and %d is %d\n", a, b, a - b);
}

/**
 * mult - function to multiply two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: product of the two integers
 */
void mult(int a, int b)
{
	printf("the multiplication is %d\n", a * b);
}

/**
 * div - function to divide two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: quotient of the two integers
 */
void div(int a, int b)
{
	printf("the division of %d by %d is %d\n", a, b, a / b);
}

/**
 * main - program entry point
 *
 * Return: 0 if success, -1 otherwise
 */
int main(void)
{
	void (*func_ptr[])(int, int) = {add, sub, mult, div};
	int i = 0, a = 15, b = 3;

	if (i > 3)
		return (-1);
	while (i < 4)
	{
		(*func_ptr[i])(a, b);
		i++;
	}
	return (0);
}

