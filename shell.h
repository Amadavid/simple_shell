#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>


/* Function prototypes */
void prompt(void);
int execute(char *command);
int execute(char *command);
char *argv[] = {command, NULL};
int execute_command(char *command);
execve(command, argv, environ);



#endif /* SHELL_H */

