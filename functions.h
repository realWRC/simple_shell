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

void interactive(char *progname);
void noninteractive(char *progname);

char *readinput();
char *searchpath(char *command);
char **split(char *string);
int execute(char *progname, char *argv[]);
int cprocess(char *progname, char *path, char *argv[]);
int validate(char *command);
char *_getenv(const char *name);

int func_exit(char *argv[]);

#endif
