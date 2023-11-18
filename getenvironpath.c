#include "sshelll.h"

/**
 * getenvironpath - Retrieves the environment variables
 * @var: Variable to be acquired
 * Return: Returns the value of the variable or NULL
 */
char *getenvironpath(char *var)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
