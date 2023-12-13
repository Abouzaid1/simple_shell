#include "shell.h"

/**
* convertIntegar - converts
*
* @num: the changed number
*
* Return: string
*/
char *convertIntegar(int num)
{
	int null_num = 0, shell;
	char *strint_var;

	shell = num;
	if (num == 0)
		null_num = 1;
	else
	{
		while (num != 0)
		{
			num = num / 10;
			null_num++;
		}
	}
	strint_var = malloc(sizeof(char) * (null_num + 1));
	if (strint_var == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	strint_var[null_num] = '\0';

	while (null_num > 0)
	{
		strint_var[null_num - 1] = '0' + (shell % 10);
		shell = shell / 10;
		null_num--;
	}
	return (strint_var);
}
