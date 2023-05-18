#include "shell.h"
/**
 * promt - function to take the inputs from user
 * @av : argument value in the function
 * @env : eviroment argument
 */
void promt(char **av, char **env)
{
	ssize_t wordst;
	char *string = NULL, *stoken;
	size_t n = 0;
	int i = 0, j, wstatus;
	pid_t fpid;
	char *args[] = {"NULL", NULL};
	#define MAX_COM 10


	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);  / Using write()
		wordst = getline(&string, &n, stdin);
		if (wordst == -1)
		{  /* getline() returns -1 on error or end-of-file */
			free(string);
			exit(EXIT_FAILURE);
		}
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;
			i++;
		}
		stoken = strtok(string, " ");
		j = 0;
		while (stoken != NULL && j < MAX_COM)
		{
			args[j] = stoken;
			stoken = strtok(NULL, " ");
			j++;
		}
		args[j] = NULL;
		fpid = fork();
		if (fpid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (fpid == 0)/*child process*/
		{
			if (execve(args[0], args, env) == -1)
			{
				write(STDOUT_FILENO, av[0], strlen(av[0]));
				write(STDOUT_FILENO, ": No such file or directory\n", 28);
			}
		}
		else
			wait(&wstatus);
	}
}
