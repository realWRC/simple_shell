#include "functions.h"
/**
 * interactive - Function that provides instruction set for intercative
 * mode.
 * @progname: Name of executing program.
 */
void interactive(char *progname)
{
	char *input = NULL;
	char **argv = NULL;
	int i = 0;
	int status = -1;

	do {
		printf("#cisfun$ ");
		input = readinput();
		argv = split(input);
		status = execute(progname, argv);
		if (argv[i] != NULL)
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
		free(input);
		free(argv);
		if (status >= 0)
			exit(status);
	} while (status == -1);
}
