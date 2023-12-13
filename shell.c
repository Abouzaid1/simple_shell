#include "shell.h"

/**
 * main - main shell to execute commands
 *
 * @argc: number
 * @argv: array
 * @env: environment variables
 *
 * Return: 0 on success, -1 on failure
 */

int main(int argc, char **argv, char **env)
{
	int counter = 1;
	(void)argc;

	while (1)
	{
		char *get_input;
		char **full_command;

		prompt();
		get_input = input();
		if (get_input[0] == '\n' || get_input == NULL)
		{
			free(get_input);
			continue;
		}
		full_command = createcommand(get_input);
		free(get_input);
		get_input = NULL;
		if (full_command == NULL)
			continue;
		if (exitfuncs(full_command) == -1)
		{
			handler(argv[0], counter, full_command, 0);
			all_command(full_command);
			if (!isatty(STDIN_FILENO))
				exit(2);
			counter++;
			continue;
		}
		if (stringcompare_func(full_command[0], "env", 3) == 0)
		{
			environment(env);
			continue;
		}
		execommand(argv, full_command, counter, env);
		all_command(full_command);
		full_command = NULL;
		counter++;
	}
	return (0);
}
