#ifndef SSHELLL_H
#define SSHELLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0

extern char **environ;

/*tokenize.c*/
char **tokenize(char *line);

/*execute.c*/
int _launch(char **cmd, char **argv, int index);
char *pickLine(void);
void free_string_array(char **array);

/*string-length.c*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);

/*getenvironpath.c*/
char *getenvironpath(char *var);

/*getfullpath.c*/
char *getfullpath(char *cmd);

/*_utils.c*/
void _perror(char *name, char *cmd, int index);
char *_atoi(int n);
void reverse_string(char *str, int len);

/*pathBuild.c*/
void show_env(char **cmd, int *status);
void terminateshell(char **cmd, char **argv, int *status, int index);
void check_b(char **cmd, char **argv, int *status, int index);
int pathbuilt(char *cmd);

int custom_atoi(char *str);
int num_is_pos(char *str);


#endif
