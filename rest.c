#include "shell.h"

/**
* stringtoint_func - converts a string into a long integer
*
* @input_string: string that changed
*
* Return: long integer
*/
long int stringtoint_func(char *input_string)
{
	int result = 0;
	int index = 0;

	if (input_string == NULL)
		return (-1);
	if (!input_string[1])
	{
		result = input_string[0] - '0';
		return (result);
	}
	while (input_string[index] != '\0')
	{
		if (input_string[index] >= '0' && input_string[index] <= '9')
			result = (result * 10) + (input_string[index] - '0');
		else
			return (-1);
		index++;
	}
	return (result);
}
