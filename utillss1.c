#include "sshelll.h"

/**
 * num_is_positive - Checks if the string represents a positive number
 * @str: The string to be checked
 *
 * Return: 1 if the string is a positive number, 0 otherwise
 */
int num_is_pos(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * custom_atoi - Converts a string to an integer
 * @str: The string to be converted
 *
 * Return: The converted integer
 */
int custom_atoi(char *str)
{
	int number = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		number *= 10;
		number += (str[i] - '0');
	}

	return (number);
}

