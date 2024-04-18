#include "functions.h"
/**
 * validate - Function that validates a command.
 * @command: Command to be validated.
 * Return: Return validation status.
 */
int validate(char *command)
{
	if (access(command, F_OK) == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}
