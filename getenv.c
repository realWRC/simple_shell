#include "functions.h"
/**
 * _getenv - Function that gets an environment variable.
 * @name: Name of desired variable.
 * Return: Environmental variable string.
 */
char *_getenv(const char *name)
{
	const char *delin = "=";
	char *envar;
	char *token;
	char *value;
	int count = 0;
	int i;

	while (environ[count] != NULL)
	{
		count++;
	}
	for (i = 0; i < count; i++)
	{
		envar = strdup(environ[i]);
		if (envar == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(envar, delin);
		if ((token != NULL && strcmp(token, name)) == 0)
		{
			token = strtok(NULL, delin);
			value = strdup(token);
			free(envar);
			return (value);
		}
		free(envar);
	}
	dprintf(STDERR_FILENO, "Variable notfoud%s", name);
	return (NULL);
}
