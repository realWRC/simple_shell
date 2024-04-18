#include "functions.h"
/**
 * searchpath - Function that searches for a commands full path in the path
 * environment varible.
 * @command: Command whose path is to be found.
 * Return: Full path command on success and original command if failed.
 */
char *searchpath(char *command)
{
	char *path, *token, *execpath;

	if (strchr(command, '/') != NULL)
	{
		return (strdup(command));
	}
	path = _getenv("PATH");
	if (path == NULL)
	{
		dprintf(STDERR_FILENO, "_getenv() failed\n");
		exit(-1);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		execpath = malloc(strlen(token) + strlen(command) + 2);
		if (execpath == NULL)
		{
			dprintf(STDERR_FILENO, "malloc in search failed\n");
			free(path);
			exit(-1);
		}
		sprintf(execpath, "%s/%s", token, command);
		if (access(execpath, F_OK) == 0)
		{
			free(path);
			return (execpath);
		}
		free(execpath);
		token = strtok(NULL, ":");
	}
	free(path);
	return (strdup(command));
}
