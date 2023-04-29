#include"shell.h"
/**
 * main - code entry point
 * getline() - read line of input from user
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
	perror("getline");
	exit(EXIT_FAILURE);
	}
	printf("You typed %s", line);

	free(line);
	return (0);
}
