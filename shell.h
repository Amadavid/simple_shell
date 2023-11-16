#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

/* Function prototypes */
void prompt(void);
int execute(char *command, char *argv[]);
int execute_command(char *command, char *argv[]);
int main(int ac, char **argv)




#endif /* SHELL_H */

