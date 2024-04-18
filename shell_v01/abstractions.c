#include "functions.h"
/**
 * freevar - Function that frees a array of strings.
 * @argvect: An array of strings.
 * @string_1: A string.
 * @string_2: A string.
 */
void freevar(char **argvect, char *string_1, char *string_2)
{
	int i = 0;

	if (argvect != NULL)
	{
		for (i = 0; argvect[i] != NULL; i++)
		{
			free(argvect[i]);
			argvect[i] = NULL;
		}
		free(argvect);
		argvect = NULL;
	}
	if (string_1 != NULL)
	{
		free(string_1);
		string_1 = NULL;
	}
	if (string_2 != NULL)
	{
		free(string_2);
		string_2 = NULL;
	}
}
/**
 * readinput - function to handle end of file.
 * Return: Returns the input string on success.
 */
char *readinput()
{
	char *input = NULL;
	ssize_t bytes_read = 0;
	size_t buff = 0;

	bytes_read = getline(&input, &buff, stdin);
	if (bytes_read == -1)
	{
		printf("\n");
		free(input);
		exit(0);
	}
	return (input);
}
/**
 * fprocess - creates child and executes all other parent
 * processes.
 * @argvect: Argument vector.
 * @pr_name: Program name(Usually from main argv[0]).
 * @path: Path argument to be pased to execve.
 */
void fprocess(char **argvect, char *pr_name, char *path)
{
	if (execve(path, argvect, environ) == -1)
	{
		dprintf(STDERR_FILENO, "%s: %s\n", pr_name, strerror(errno));
		exit(-1);
	}
}
/**
 * argccount - Function abstraction for making use of argc.
 * @argc: Argument count.
 */
void argccount(int argc)
{
	if (argc != 1)
	{
		dprintf(STDERR_FILENO, "Run program first to execute commands\n");
		exit(-1);
	}
}
