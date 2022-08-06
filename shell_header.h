#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

void prompt_function(void);
void mode_function(int m);
void exit_function(char **cmd, char *get_in);
void environment_function(void);
void run_command(char *cp, char **cmd);
void free_buffer(char **buf);
int checker_function(char **cmd, char *buf);
int builtin_handler(char **cmd, char *get_in);
int _strcmp(char *in1, char *in2);
int _strlen(char *s);
int _strncmp(char *in1, char *in2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);
char **token_function(char *get_in);
char *path_function(char **path, char *cmd);
char *path_append(char *path, char *cmd);
char *findpath_function(void);
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#endif
