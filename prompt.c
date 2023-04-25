#include "shell.h"
/**
 * main - main function to prompt the user
 * Return: 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGHT];

	while (1)
	{
		/*Display the prompt and wait for the user to type a command*/
		printf(PROMPT);
		fflush(stdout);
		if (fgets(command, MAX_COMMAND_LENGHT, stdin) == NULL)
		{
			/*end of file*/
			printf("\n");
			break;
		}
		/*remove the new line char from end of command*/
		command[strcspn(command, "\n")] = '\0';
		execute_command(command);
	}
	return (0);
}
