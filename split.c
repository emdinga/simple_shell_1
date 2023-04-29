#include "shell.h"
/**
 * split_string() - splits string
 * @str: string to split
 * @delim: the delimeter to use when splitting the string
 * @count: pointer to integer
 *
 * main - entry point
 *
 * Return: Always 0
 */

char **split_string(char *str, const char *delim, int *count)
{
	char **arr = (char **) malloc(sizeof(char *) * 10);

	if (arr == NULL)

	{
	perror("malloc");
	exit(EXIT_FAILURE);
	}
	char *token = strtok(str, delim);
	int i = 0;

	while (token != NULL)

	{
	arr[i] = token;
	i++;
	token = strtok(NULL, delim);
	}
	arr[i] = NULL;
	*count = i;

	return (arr);
}

int main(void)
{
	char str[] = "The quick brown fox jumps over the lazy dog";
	int count;
	char **arr = split_string(str, " ", &count);

	for (int i = 0; i < count; i++)
	{
	printf("%s\n", arr[i]);
	}

	free(arr);

	return (0);
}
