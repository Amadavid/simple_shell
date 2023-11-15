#include "shell.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
* prompt - Display the shell prompt and handle user input.
*
* Return: 0
*/
void prompt(void)
{
char *command = NULL;
ssize_t read_bytes;

while (1)
{
/* Display the shell prompt */
char *prompt_str = "($) ";

write(STDOUT_FILENO, prompt_str, strlen(prompt_str));

/* Read user input */
command = NULL;
read_bytes = getline(&command, NULL, stdin);

if (read_bytes == -1)
{
if (command)
free(command);
break;  /* Handle end-of-file condition (Ctrl+D) */
}


if (read_bytes > 0 && command[read_bytes - 1] == '\n')
command[read_bytes - 1] = '\0';

/* Execute the command and get the return status */
execute(command);

if (command)
free(command);  /* Free the allocated memory for command */
}
}

