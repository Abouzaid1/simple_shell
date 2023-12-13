#include "shell.h"

/**
* prompt - gives "$ " prompt to the user
* @shell_sign: the sign of the shell
* Return: void
*/
void prompt(void)
{
	char *shell_sign = "$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, shell_sign, 2);
	}
}

/**
* env - prints environment variables
*
* @env_variable: environment variables
*
* Return: void
*/
void environment(char **env_variable)
{
	int index;

	index = 0;
	while (env_variable[index] != NULL)
	{
		write(STDOUT_FILENO, env_variable[index], strLen_func(env_variable[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}
