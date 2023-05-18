#include "shell.h"
/**
 * main - Entry point
 * promt - function to promt for input
 * @av : argument values
 * @ac : number of argument count
 * @env : - enviroment variables
 * Return: always 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		prompt(av, env);
	}
	return (0);
}

