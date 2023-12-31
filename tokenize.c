#include "sshelll.h"

/**
 * tokenize - split a string into commands
 * @line: string to be tokenized
 *
 * Return: token
 */
char **tokenize(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line);
		free(tmp);
		return (NULL);
	}

	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);

	cmd = malloc(sizeof(char *) * (cpt + 1));
	if (!cmd)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		cmd[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line);
	cmd[i] = NULL;
	return (cmd);
}

