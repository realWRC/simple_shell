#include "functions.h"
/**
 * split - Function that tokenises a string.
 * @string: String to tokenize
 * Return: String token array
 */
char **split(char *string)
{
	char *tokens;
	char **token_array;
	const char *delin = " \t\n";
	int count = 0;

	tokens = strtok(string, delin);
	token_array = (char **)malloc(sizeof(char *));
	while (tokens != NULL)
	{
		token_array = (char **)realloc(token_array, (count + 2) * sizeof(char *));
		token_array[count] = strdup(tokens);
		tokens = strtok(NULL, delin);
		count++;
	}
	token_array[count] = NULL;
	return (token_array);
}
