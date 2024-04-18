#include "functions.h"
/**
 * split - Function that tokenises a string.
 * @string: String to tokenize.
 * Return: String token array.
 */
char **split(char *string)
{
	char *tokens;
	char **token_array;
	const char *delin = " \t\n";
	int count = 0;

	token_array = (char **)malloc(sizeof(char *));
	if (token_array == NULL)
	{
		dprintf(STDERR_FILENO, "Malloc in split failed\n");
		exit(EXIT_FAILURE);
	}
	tokens = strtok(string, delin);
	while (tokens != NULL)
	{
		token_array = (char **)realloc(token_array, (count + 2) * sizeof(char *));
		if (token_array == NULL)
		{
			dprintf(STDERR_FILENO, "Malloc in split failed\n");
			exit(EXIT_FAILURE);
		}
		token_array[count] = strdup(tokens);
		tokens = strtok(NULL, delin);
		count++;
	}
	token_array[count] = NULL;
	return (token_array);
}
