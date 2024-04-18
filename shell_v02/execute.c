#include "functions.h"
/**
 * execute - Function for command execution.
 * @argv: Argument Vector.
 * @progname: Name of executing program.
 * Return: Status value.
 */
int execute(char *progname, char *argv[])
{
	char *path = NULL;
	unsigned long int i = 0;
	char *builtin_list[] = {"exit"};

	int (*builtin_functions[])(char **) = {&func_exit};

	if (argv == NULL || argv[0] == NULL)
	{
		return (-1);
	}
	while (i < sizeof(builtin_list) / sizeof(char *))
	{
		if (strcmp(argv[0], builtin_list[i]) == 0)
		{
			return ((*builtin_functions[i])(argv));
		}
		i++;
	}
	path = searchpath(argv[0]);
	if (access(path, F_OK) != 0)
	{
		dprintf(STDERR_FILENO, "%s: ", progname);
		perror("");
		return (-1);
	}
	return (cprocess(progname, path, argv));
}
