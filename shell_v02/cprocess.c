#include "functions.h"
/**
 * cprocess - Function that creates a child process to execute
 * commands.
 * @progname: Program name.
 * @path: Command path.
 * @argv: Argument Vector.
 * Return: Status value.
 */
int cprocess(char *progname, char *path, char *argv[])
{
	pid_t child;
	int status;

	child = fork();
	if (child < 0)
	{
		perror("");
	}
	if (child == 0)
	{
		if (execve(path, argv, environ) == -1)
		{
			dprintf(STDERR_FILENO, "%s: %s\n", progname, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(path);
	}
	return (-1);
}
