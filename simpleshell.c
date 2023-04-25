#include "shell.h"

/**
 * display_prompt - Main function to prompt a user
 *
 * Return: 0 success
*/

void display_prompt(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s> ", cwd);
	}
	else
	{
		perror("getcwd() error");
		exit(EXIT_FAILURE);
	}
}
