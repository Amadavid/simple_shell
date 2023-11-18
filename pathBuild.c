#include "sshell.h"

/**
 * pathbuilt - Constructs a list of built-in commands
 * @cmd: The command to be built-in
 *
 * Return: 0 if successful, 1 otherwise
 */
int pathbuilt(char *cmd)
{
	char *b_i[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
	int i;

	for (i = 0; b_i[i]; i++)
	{
		if (_strcmp(cmd, b_i[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * check_b - Handles execution of built-in commands
 * @cmd: Command to be executed
 * @argv: Array of arguments
 * @status: Status code of the command
 * @index: Void parameter
 */
void check_b(char **cmd, char **argv, int *status, int index)
{
	(void)argv;
	(void)index;

	if (_strcmp(cmd[0], "exit") == 0)
		_quit_shell(cmd, argv, status, index);
	else if (_strcmp(cmd[0], "env") == 0)
		_display_env(cmd, status);
}

/**
 * terminateshell - Terminates the interactive shell
 * @cmd: Command to exit the shell
 * @argv: Array of arguments
 * @index: Void parameter
 * @status: Exit status code
 */
void terminateshell(char **cmd, char **argv, int *status, int index)
{
	int exit_val = (*status);
	char *qindex, msg[] = ": exit: Forbidden number: ";

	if (cmd[1])
	{
		if (num_is_pos(cmd[1]))
		{
			exit_val = custom_atoi(cmd[1]);
		}
		else
		{
			qindex = _atoi(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, qindex, _strlen(qindex));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(qindex);
			free_string_array(cmd);
			(*status) = 2;
			return;
		}
	}
	free_string_array(cmd);
	exit(exit_val);
}

/**
 * show_env - Outputs the environment variables
 * @cmd: Command for printing environment variables
 * @status: Void parameter
 */
void show_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_string_array(cmd);
	(*status) = 0;
}

