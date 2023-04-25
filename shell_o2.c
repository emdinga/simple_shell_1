#include "shell.h"
/**
 * @args: the actual argument
 * strtok - tokenizes the arguments
 * Return: NULL if fgets encounters a end-of-file character program exits
 */
int main()
{
	char command[MAX_XOMMAND_LENGHT];
	pid_t pid;
	int status;
	int i;
	char *args[MAX_XOMMAND_LENGHT];

	while (1)
	{
	printf("$");
	fflush(stdout);
	if (fgets(command, MAX_XOMMAND_LENGHT, stdin) == NULL)
	{
	printf("\n");
	break;
	}
	command[strcspn(command, "\n")] = '\0';
	i = 0;

	args[i] = strtok(command, " ");
	while (args[i] != NULL)
	{
	i++;
	args[i] = strtok(NULL, " ");
	}
	if (args[0] == NULL)
	{
	continue;
	}
	pid = fork();
	if (pid < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	if (execve(command, args, NULL) < 0)
	{
	perror("execvp");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	waitpid(pid, &status, 0);
	}
	}
	return (0);
}
