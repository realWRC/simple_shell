#include "functions.h"
/**
 * noninteractive - Function with instructions for non interactive
 * mode.
 * @progname: Name of program running the commands.
 */
void noninteractive(char *progname)
{
	char *input;
	char **argv;
	int status = -1;

	do {
		input = readinput();
		argv = split(input);
		status = execute(progname, argv);
		free(input);
		free(argv);
		if (status >= 0)
			exit(status);
	} while (status == -1);
}
