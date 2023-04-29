#include "shell.h"
/**
 * main - access command-line arguments
 * argc - number of arguments
 * argv - array of string containing arguments
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
	{
	printf("%d\n", argv[i]);
	}

	return (0);
}
