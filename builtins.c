#include "functions.h"
/**
 * func_exit - Function for exiting shell.
 * @argv: Argument vector.
 * Return: Status value.
 */
int func_exit(char *argv[])
{
	if (strcmp(argv[0], "exit") == 0)
	{
		return (0);
	}
	return (-1);
}
