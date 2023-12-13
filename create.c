#include "shell.h"

/**
 * createcommand - creates an array of strings from a command
 *
 * @com: command to create an array of strings from
 *
 * Return: array of strings of the full command
 */
char **createcommand(const char *com)
{
	int nullcom, i;
	const char *delim = " \t\n";
	char *comcpy, *onecommand;
	char **allcommand;

	if (com == NULL)
		return (0);
	nullcom = countcom(com);
	if (nullcom == 0)
		return (NULL);
	comcpy = strduplicate_func(com);
	allcommand = malloc(sizeof(char *) * (nullcom + 1));
	if (allcommand == NULL)
	{
		perror("malloc");
		all_command(allcommand);
		free(comcpy);
		exit(1);
	}
	onecommand = strtok(comcpy, delim);
	for (i = 0; onecommand != NULL; i++)
	{
		allcommand[i] = malloc(sizeof(char) * strLen_func(onecommand) + 1);
		if (allcommand[i] == NULL)
		{
			perror("malloc");
			all_command(allcommand);
			free(comcpy);
			free(onecommand);
			exit(1);
		}
		strcopy_func(allcommand[i], onecommand);
		onecommand = strtok(NULL, delim);
	}
	allcommand[i] = NULL;
	free(comcpy);
	comcpy = NULL;
	free(onecommand);
	return (allcommand);
}
