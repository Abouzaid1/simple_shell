#include "shell.h"

/**
 * handler - prints error messages like sh
 *
 * @yet: my shell's yet
 * @com: com written
 * @countnum: com countnum
 * @yetstatu: error yetstatu, put 0 for exit, otherwise 1
 *
 * Return: void
 */
void handler(char *yet, int countnum, char **com, int yetstatu)
{
	char *string_countnum;

	string_countnum = _int_to_string(countnum);
	write(STDERR_FILENO, yet, _stringlen(yet));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, string_countnum, _stringlen(string_countnum));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, com[0], _stringlen(com[0]));
	write(STDERR_FILENO, ": ", 2);
	if (yetstatu == 1)
		write(STDERR_FILENO, "not found", 9);
	else
	{
		write(STDERR_FILENO, "not a ", 14);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, com[1], _stringlen(com[1]));
	}
	write(STDERR_FILENO, "\n", 1);

	free(string_countnum);
}