#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define BUFFER_SIZE 1024
#define MAX_XOMMAND_LENGHT 1024
static char buf[BUFFER_SIZE];
static char *buf_ptr = buf;
static size_t buf_len = 0;
extern char **environ;

typedef struct Command 
{
	char **args;
	int *bg;

	struct command *next;
}command;


typedef struct Built_in_command
{
	char *name;
	void (*func)(command *cmd);
}built_in_command;

void display_prompt (void);
command *parse_cmd(char *input, char *token);
void exit_command(command *cmd);
void setenv_command(command *cmd);
void unsetenv_command(command *cmd);
void cd_command(command *cmd);
char *getline_custom(int (*get_char)(void));

#endif
