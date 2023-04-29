#include "shell.h"
/**
 * main - entry point of thr program
 *
 * fork - create child process
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char* args[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (1)
	{
	printf("#cisfun$ ");
	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
	break;
	}

	if (line[nread - 1] == '\n')
	{
	line[nread - 1] = '\0';
	}
	char *token = strtok(line, " ");
	char *command = token;

	if (command == NULL)
	{
	continue;
	}
	pid_t pid = fork();

	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	execve(args[0], args, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
	}
	else
	{
	int status;

	waitpid(pid, &status, 0);
	}
	}
	free(line);
	return (0);
}
