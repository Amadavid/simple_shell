#include "shell.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char *command = NULL; /* Initialize command to NULL */
/**
* execute_command - Execute a command entered by the user.
* @command: The command to execute.
* Return: 0 on success, 1 on failure.
*/
int execute_command(char *command)

{
char *argv[] = {command, NULL}; /* Argument vector for the command */

if (execve(command, argv, environ) == -1)
{
perror("execve");
exit(1); /* Error */
}

return (0); /* Return 0 on success */
}

/**
* execute - Execute a command entered by the user.
* @command: The command to execute.
* Return: 0 on success, 1 on failure.
*/
int execute(char *command)
{
if (command == NULL || command[0] == '\0')
return (1); /* Error */

if (fork() == 0)
{
/* This code is executed by the child process */
return (execute_command(command));
}
else
{
/* This code is executed by the parent process */
int status;
if (wait(&status) == -1)
{
perror("wait");
return (1); /* Error */
}
return (WEXITSTATUS(status));
}
}

