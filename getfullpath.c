#include "sshelll.h"

/**
 * getfullpath - obtains the environment path to locate commands
 * @cmd: the command to be located by getfullpath
 * Return: NULL or the path of the command
 */
char *getfullpath(char *cmd)
{
	char *env_path, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	env_path = getenvironpath("PATH");
	if (!env_path)
		return (NULL);

	dir = strtok(env_path, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &st) == 0)
			{
				free(env_path);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}
