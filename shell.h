#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define MAX_ARGS 10
#define BUFFER_SIZE 1024
#define MAX_XOMMAND_LENGHT 1024
#define MAX_COMMAND_LENGHT 256
#define PROMPT ">> "

static char buffer[BUFFER_SIZE];
/*static char *buf_ptr = buf;*/
static size_t buf_len;
extern char **environ;
static int chars_left;
static char *cursor = buffer;

/**
 * struct Command - struct function for command
 * @args: Parameter value 1
 * @bg: parameter value 2
 * @next: parameter value 3
 */
typedef struct Command
{
	char **args;
	char *bg;
	struct command *next;
} command;

/**
 * struct Built_in_command - struct function for buildt in
 * @name: parameter value 1
 * @func: parameter value 2
 */
typedef struct Built_in_command
{
	char *name;
	void (*func)(command *cmd);
} built_in_command;


void display_prompt(void);
command *parse_cmd(char *input, char *token);
void exit_command(command *cmd);
void setenv_command(command *cmd);
void unsetenv_command(command *cmd);
void cd_command(command *cmd);
char *getline_custom(int (*get_char)(void));
int main(void);
int execute_command(char **args);
char **split_input(char *input);
void handle_user_input(void);

#endif
