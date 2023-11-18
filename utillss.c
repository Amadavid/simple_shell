#include "sshelll.h"

/**
 * free_string_array - Release memory allocated to the token array
 * @array: The array whose allocated memory needs to be freed
 *
 * Return: void
 */
void free_string_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
}

/**
 * _perror - Output error messages to stderr
 * @name: Name of the errant argument
 * @cmd: Command name
 * @index: Error code
 *
 * Return: void
 */
void _perror(char *name, char *cmd, int index)
{
	char *idx, msg[] = ": not found\n";

	idx = _atoi(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(idx);
}

/**
 * _atoi - Convert integer to string
 * @n: Integer to be converted
 *
 * Return: Pointer to a string
 */
char *_atoi(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		do {
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		} while (n > 0);
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}

/**
 * reverse_string - Reverse a string
 * @str: String to be reversed
 * @len: Length of the string to be reversed
 *
 * Return: void
 */
void reverse_string(char *str, int len)
{
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		str[start] ^= str[end];
		str[end] ^= str[start];
		str[start++] ^= str[end--];
	}
}

