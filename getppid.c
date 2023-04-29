#include "shell.h"
/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
	fprintf(stderr, "failed to fork\n");
	return (1);
	}
	else if (pid == 0)
	{
	printf("child process: PID = %d, PPID =%d\n", getpid(), getppid());
	return (0);
	}
	else
	{
	printf("parent process: PID = %d, child PID = %d\n" getpid(), pid);
	wait(NULL);
	return (0);
	}
}
