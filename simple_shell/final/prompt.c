#include "shell.h"
/**
 * prompt - Shell prompt to take user inputs and execute commands.
 * @env: Array of environment variables.
 * @av: Array of command-line arguments.
 */

void prompt(char **av, char **env)
{
	ssize_t wordst;
	char *string = NULL;
	size_t n = 0;
	pid_t fpid;
	char *args[] = {"NULL", NULL};
	#define MAX_COM 10
	int wstatus;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", getLength("#cisfun$ "));
		wordst = getline(&string, &n, stdin);
		if (wordst == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (wordst == 1)
		{
			continue; /*Skip the rest of the loop and prompt again*/
		}
		processInput(string, args);
		fpid = fork();
		if (fpid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (fpid == 0)
			executeCommand(args, av, env);
		else
			wait(&wstatus);
	}
}

