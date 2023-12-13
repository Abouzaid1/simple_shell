#include "shell.h"

/**
* all_command - free a full command  array
*
* @fullque: array of command
* 
* Return: void
*/

void all_command(char **fullque)
{
	int index;

	index = 0;
	while (fullque[index] != NULL)
	{
		free(fullque[index]);
		index++;
	}
	free(fullque);
}

/**
* execommand - executes a command provided by the user
*
* @argv: main program arguments
* @com: array of string as command and its arguments
* @countnum: command counter
* @enviro: environment
*
* Return: 0 on success
*/
int execommand(char **argv, char **com, int countnum, char **enviro)
{
	pid_t childvar;
	int yetstatu;
	char *cmd = checkpathcorrection(com[0]);

	if (cmd == NULL)
	{
		handler(argv[0], countnum, com, 1);
		free(cmd);
		if (isatty(STDIN_FILENO))
			return (127);
		exit(127);
	}

	if (argv == NULL)
	{
		all_command(com);
		free(cmd);
		return (1);
	}
	childvar = fork();

	if (childvar < 0)
	{
		perror("fork");
		all_command(com);
		free(cmd);
		exit(1);
	}
	else if (childvar == 0)
		execve(cmd, com, enviro);
	else
	{
		free(cmd);
		waitpid(childvar, &yetstatu, 0);
	}
	return (0);
}
