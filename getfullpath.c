#include "sheell.h"

/**
 * getFullPath - get the full PATH to @command
 *
 * @Directory: path in the PATH environment variable
 * @command: The available command to be executed
 *
 * Return: The full path to @command
*/
char *getFullPath(char *Directory, char *command)
{
	return (pathBuild(3, Directory, "/", command));
}
