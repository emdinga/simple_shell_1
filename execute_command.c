#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * execute_command - Executes a command
 * @cmd: An array of arguments for the command
 *
 * Return: 1 if successful, 0 otherwise
 */
void execute_command(char *cmd)
{
	extern char **environ;
	pid_t pid;
	int status;

	pid = fork();
	if  (pid == 0)
	{
		/*child process*/
		char *args[] = {cmd, NULL};

		if (execve(cmd, args, environ) == -1)
		{
			perror(cmd);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			/*forking erroe*/
			perror("fork");
		}
		else
		{
			/*parent process*/
			do {
				waitpid(pid, &status, WUNTRACED);
			}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}
