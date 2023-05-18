#ifndef SHELL_H
#define SHELL_H

/* Libraries Used */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void prompt(char **av, char **env);
void processInput(char *string, char **args);
size_t getLength(const char *str);
void executeCommand(char **args, char **av, char **env);

#endif
