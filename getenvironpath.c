#include "sheell.h"

/**
* getEnvironpathvar - get the PATH from the environ variables
*
* Return: know value of the PATH variable from the environ variables
*/
char *getEnvironpathvar()
{
char *path = NULL;
char *pathValue = NULL;
envnode *current = NULL;

current = envListhead;

do
{
path = current->name;
if (isvarpathenviron(path) == IS_PATH_VARIABLE)
{
pathValue = current->envValue;
break;
}
current = current->next;
}
while (current != NULL);
return (pathValue);
}
