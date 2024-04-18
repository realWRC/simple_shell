#include "functions.h"
/**
 * main - Function entry point.
 * @argc: Argument count.
 * @argv: Argument Vector.
 * Return: Always 0 on success.
 *
 * Description: This is a simple shell with limited functionality.
 * This shell assumes execve and fork never fail.
 */
int main(int argc, char *argv[])
{
	pid_t child = 0;
	int i, status = 0;
	char *path, *input = NULL;
	char **argvect = NULL;

	argccount(argc);
	for (;;)
	{
		printf("#cisfun$ ");
		input = readinput();
		argvect = split(input);
		if (argvect[0] == NULL)
		{
			freevar(argvect, input, NULL);
			continue;
		}
		if (strcmp(argvect[0], "exit") == 0)
		{
			freevar(argvect, input, NULL);
			break;
		}
		path = searchpath(argvect[0]);
		child = fork();
		if (child == -1)
			exit(-1);
		if (child == 0)
			fprocess(argvect, argv[0], path);
		else
		{
			wait(&status);
			for (i = 0; argvect[i] != NULL; i++)
				free(argvect[i]);
			free(input);
			free(argvect);
			free(path);
			input = NULL;
			argvect = NULL;
		}
	}
	return (0);
}
