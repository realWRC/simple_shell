#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char **split(char *string);
char *_getenv(const char *name);
char *searchpath(char *command);
char *readinput();
void argccount(int argc);
void fprocess(char **argvect, char *pr_name, char *path);
void freevar(char **argv, char *string_1, char *string_2);

#endif
