#include "shell.h"

/**
 * exit_command - Main fubction for exit
 * @cmd: pointer to take user commands
 * Return: 0
 */

void exit_command(command *cmd)
{
	exit(0);
}

/**
 * env_command - function to pars environment
 * @cmd: pointer to user command
 * Return: 0
 */

void env_command(command *cmd)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env++);
	}
}

/**
 * setenv_command - function to handle built in commands
 * @cmd: pointer to user input
 */

void setenv_command(command *cmd)
{
	if (cmd->args[1] && cmd->args[2])
	{
		setenv(cmd->args[1], cmd->args[2], 1);
	}
	else
	{
		printf("usage: sentev <var> <value>\n");
	}
}

/**
 * unsetenv_command - function to handle built in commands
 * @cmd: pointer to the user input
 */

void unsetenv_command(command *cmd)
{
	if (cmd->args[1])
	{
		unsetenv(cmd->args[1]);
	}
	else
	{
		printf("usage: unsetenv <var>\n");
	}
}

/**
 * cd_command -  Main function
 * @cmd: pointer to usr iput
 * Return: 0
 */

void cd_command(command *cmd)
{
	if (cmd->args[1])
	{
		if (chdir(cmd->args[1]) == -1)
		{
			perror("cd");
		}
		else
		{
			chdir(getenv("HOME"));
		}
	}
}
