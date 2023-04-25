#include "shell.h"

/**
 * parse_cmd - main functuin to parse new commands
 * @input: user input
 * @token: pointer
 * Return: cmd
 */


command *parse_cmd(char *input, char *token)
{
	char **args = malloc(sizeof(char *) * MAX_ARGS);
	int i = 0;

	while (token = strtok_r(input, " ", &input))
	{
		args[i++] = token;
	}

	args[i] = NULL;

	command *cmd = malloc(sizeof(command));

	cmd->args = args;
	cmd->bg = 0;
	cmd->next = NULL;

	return (cmd);
}
