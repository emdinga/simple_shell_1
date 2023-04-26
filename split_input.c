#include "shell.h"

/**
 * split_input - Splits a string into an array of tokens
 * @input: The string to split
 *
 * Return: An array of tokens
 */
char **split_input(char *input)
{
	int i = 0;
	char *token = NULL;
	char **tokens = malloc(sizeof(char *) * 64);

	if (!tokens)
	{
		fprintf(stderr, "Error: Allocation failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t\r\n\a");

	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;

	return (tokens);
}
