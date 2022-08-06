#include "shell_header.h"
/**
* main - function that reads, execute and print user input
* @argc: int
* @argv: char
* @envp: environment vector
*
* Return: 0
*/

int main(int argc, char **argv, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)argv;
	if (argc < 1)
		return (-1);
	signal(SIGINT, mode_function);
	while (1)
	{
		free_buffer(command);
		free_buffer(paths);
		free(pathcommand);
		prompt_function();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = token_function(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (checker_function(command, line))
			continue;
		path = findpath_function();
		paths = token_function(path);
		pathcommand = path_function(paths, command[0]);
		if (!pathcommand)
			perror(argv[0]);
		else
			run_command(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
