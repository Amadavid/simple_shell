#include "sshelll.h"

/**
 * _launch - executes instructions after  parsing
 * @cmd: instructions to be executed
 * @argv: array  arguments to follow the instructions
 * @index: guide for the instructions
 * Return: return status
 */
int _launch(char **cmd, char **argv, int index)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = getfullpath(cmd[0]);
	if (!full_cmd)
	{
		_perror(argv[0], cmd[0], index);
		free_string_array(cmd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			free_string_array(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_string_array(cmd);
		free(full_cmd);
		full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}

