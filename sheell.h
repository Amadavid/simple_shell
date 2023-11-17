#ifndef SHEELL_H
#define SHEELL_H

#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <signal.h>

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0
#define MAX_BUFFER 204

int _userprompt(char **commandBuffer, size_t *bytesRead);
char **tokenizeString(char *inputStr, char *delimiter);
char *getEnvironpathvar();
char *pathBuild(int numStrings, ...);
char *getFullPath(char *Directory, char *command);
char *string_copy(char *destination, char *source);
int string_length(char *str_to_measure);
int _checkmode(void);
int checkEnvironmentCommand(char *command);
int putcharr(char character, int fd);
int displayEnvironment(void);





#endif
