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

void promt(char **av, char **env);

#endif
