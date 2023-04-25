#include "shell.h"

/**
 * execute_command - Main function to prompt a user
 * @command: parameter value
 * Return: 0
 */

void execute_command(char *command)
{
	pid_t pid;
	int status;
	/*create a new process to execute the command */

	pid = fork();

	if (pid == 0)
	{
		/*child process*/
		char *argv[] = { command, NULL };
		char *envp[] = { NULL };

		if (execve(command, argv, envp) == -1)

		{
			fprintf(stderr, "Error: could not execute '%s'.\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		/*parent process*/
		if (waitpid(pid, &status, 0) < 0)
		{
			fprintf(stderr, "Error: waitpid failed.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Fork failed */
		fprintf(stderr, "Error: fork failed.\n");
		exit(EXIT_FAILURE);
	}
}
