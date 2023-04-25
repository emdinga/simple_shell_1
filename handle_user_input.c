#include "shell.h"

/**
 * handle_user_input - Handles user input
 */
void handle_user_input(void)
{
	char *input = NULL;
	char **args = NULL;
	size_t input_size = 0;
	ssize_t chars_read;

	while (1)
	{
		printf("#cisfun$ ");
		chars_read = getline(&input, &input_size, stdin);
		if (chars_read == -1)
		{
			printf("\n");
			break;
		}
		args = split_input(input);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				break;
			}
			execute_command(args);
		}

		free(input);
		free(args);
		input = NULL;
		args = NULL;
		input_size = 0;
	}
}
