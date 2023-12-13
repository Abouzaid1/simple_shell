#include "shell.h"

/**
* input - get's input from the user
*
* Return: pointer to string holding input
*/
char *input(void)
{
	char *my_input = NULL;
	size_t n = 0;
	ssize_t nullchars;

	nullchars = getline(&my_input, &n, stdin);
	if (nullchars == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		free(my_input);
		exit(0);
	}

	return (my_input);
}

/**
 * path - gets the value of the variable PATH
 *
 * Return: value of PATH variable
*/
char *path(void)
{
	int index;

	if (environ == NULL)
		return (NULL);

	for (index = 0; environ[index] != NULL; index++)
	{
		if ((stringcompare_func(environ[index], "PATH", 4)) == 0)
			return (environ[index] + 5);
	}
	return (NULL);
}
