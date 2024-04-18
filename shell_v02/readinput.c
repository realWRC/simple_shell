#include "functions.h"
/**
 * readinput - function that read input to shell.
 * Return: Returns the input string on success.
 */
char *readinput()
{
	char *input = NULL;
	size_t buff = 0;
	ssize_t bytes_read = 0;

	bytes_read = getline(&input, &buff, stdin);
	if (bytes_read == -1)
	{
		if (feof(stdin))
		{
			/*printf("\n");*/
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("readline() failed");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
