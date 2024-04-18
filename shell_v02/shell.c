#include "functions.h"
/**
 * main - Program entry point.
 * @argc: Argument Count.
 * @argv: Argument Vector.
 * Return: Always (0) on success.
 */
int main(int argc, char *argv[])
{
	if (argc < 1)
	{
		exit(EXIT_FAILURE);
	}
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive(argv[0]);
	}
	else
	{
		noninteractive(argv[0]);
	}
	return (0);
}
