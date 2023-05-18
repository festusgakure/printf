#include "shell.h"

/**
 * executeCommand - Execute the command specified by args.
 * @args: Array of arguments.
 * @av: Array of command-line arguments.
 * @env: Array of environment variables.
 */
void executeCommand(char **args, char **av, char **env)
{
	char *str = ": No such file or directory\n";

	if (execve(args[0], args, env) == -1)
	{
		write(STDOUT_FILENO, av[0], getLength(av[0]));
		write(STDOUT_FILENO, str, getLength(str));
		exit(EXIT_FAILURE);
	}
}

