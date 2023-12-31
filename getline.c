#include "sshelll.h"

/**
 * pickLine - Reads input from the user
 *
 * Return: Returns a string having the input read from the user
 */
char *pickLine(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t i;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		i = getline(&line, &len, stdin);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
	}

	return (line);
}

