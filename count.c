#include "shell.h"

/**
 * countcom - count number of commands
 *
 * @com: full command to count its number of commands
 *
 * Return: number of commands
 */
int countcom(const char *com)
{
	char *onecommand, *comcpy;
	const char *delim = " \t\n";
	int nullcommand = 0;

	comcpy = strduplicate_func(com);

	onecommand = strtok(comcpy, delim);
	while (onecommand != NULL)
	{
		nullcommand++;
		onecommand = strtok(NULL, delim);
	}
	free(comcpy);
	free(onecommand);
	return (nullcommand);
}
