#include "shell.h"

/**
 * main - entry point of thr program
 * @args: the actual argument
 * fgets - reads commands from users
 * fork - create child process
 * Return: NULL if fgets encounters the end-of-file character, program exits
 */
int main(void)
{
	char command[MAX_XOMMAND_LENGHT + 1];
	char *args[2];
	pid_t pid;

	while (1)
	{
	printf("$");
	fflush(stdout);
	if (fgets(command, MAX_XOMMAND_LENGHT, stdin) == NULL)
	break;
	}
	command[strcspn(command, "\n")] = '\0';
	pid = fork();
	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;
		if (execve(command, args, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
	else
	{
		int status;
	waitpid(pid, &status, 0);
	}
	}
	return (0);
}
