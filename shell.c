#include "shell.h"

/**
 * main - entry point of thr program
 * fgets - reads commands from users
 * fork - create child process
 * Return: NULL if fgets encounters the end-of-file character, program exits
 */

int main(void)
{
	char cmd[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		if (fgets(cmd, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		cmd[strcmp(cmd, "\n")] = '\0'; /*remove trailing newlines*/

		if (strcmp(cmd, "exit") == 0)
		{
			break;
		}
		if (cmd[0] == '/')
		{
			execute_command(&cmd[0]);
		}
		else
		{
			char full_cmd[MAX_COMMAND_LENGTH + 10]; /*adding space for bin*/

			snprintf(full_cmd, MAX_COMMAND_LENGTH + 10, "/bin/%s", cmd);
			execute_command(&full_cmd[0]);
		}
	}
	return (0);
}
