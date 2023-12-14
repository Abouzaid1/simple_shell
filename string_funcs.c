#include "shell.h"

/**
* stringcompare_func - compares two strings up to a specified number of bytes
*
* @str_one: first string
* @str_two: second string
* @num_b: number of bytes to compare
*
* Returns: 0 if strings are equal up to num_bytes, 1 otherwise
*/
int stringcompare_func(const char *str_one, const char *str_two, size_t num_b)
{
	size_t index = 0;

	for (index = 0; index < num_b; index++)
	{
		if (str_one[index] != str_two[index])
			return 1;
	}
    return 0;
}

/**
* strLen_func - calculate length of input excluding \0
*
* @my_input: custom string
* @my_length: length of input
* 
* Return: length of the custom string
*/
int strLen_func(const char *my_input)
{
    int my_length = 0;

    for (my_length = 0; my_input[my_length] != '\0'; my_length++)
		;
    return my_length;
}

/**
* strduplicate_func - duplicates a string
*
* @original: string to be duplicated
*
* Return: duplicate  string
*/
char *strduplicate_func(const char *original)
{
    char *duplicate;
    int index;

    duplicate = malloc(sizeof(char) * (strLen_func(original) + 1));
    if (duplicate == NULL)
    {
        perror("malloc");
        exit(1);
    }

    for (index = 0; original[index] != '\0'; index++)
        duplicate[index] = original[index];

    duplicate[index] = '\0';
    return duplicate;
}

/**
* strcopy_func - copies a string from source to destination
*
* @destination: string to copy to
* @source: string to copy from
*
* Return: pointer to the destination
*/
char *strcopy_func(char *destination, const char *source)
{
    int index;

    for (index = 0; source[index] != '\0'; index++)
        destination[index] = source[index];

    destination[index] = '\0';
    return destination;
}

/**
* customStrConcat - concatenate source string to destination string
*
* @destination: destination string to concatenate to
* @source: source string to concatenate from
*
* Return: new destination string
*/
char *strconcat_func(char *destination, const char *source)
{
    int destIndex, srcIndex;

    if (source == NULL)
        return destination;

    for (destIndex = 0; destination[destIndex] != '\0'; destIndex++)
        ;

    for (srcIndex = 0; source[srcIndex] != '\0'; srcIndex++)
        destination[srcIndex + destIndex] = source[srcIndex];

    destination[srcIndex + destIndex] = '\0';
    return destination;
}
