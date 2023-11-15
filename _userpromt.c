#include "sheell.h"

/**
* _userprompt - Displays a user prompt and captures a command to execute.
*
* @commandBuffer: Pointer to the memory location where the entered command is stored.
* @bytesRead: Pointer to a variable tracking the number of bytes read.
*
* Return: EXIT if a command is stored in @commandBuffer, EOF if
* the end of the input is reached.
*/

int _userprompt(char **commandBuffer, size_t *bytesRead)
{
int bytesReadResult = 0;
int executionMode = NON_INTERACTIVE_MODE;

executionMode = _checkmode();
if (executionMode == INTERACTIVE_MODE)
{
write(STDOUT_FILENO, "# ", 2);
}
bytesReadResult = getline(buffer, bytesRead, stdin);
if (bytesReadResult == EOF)
{
if (executionMode == INTERACTIVE_MODE)
{
write(STDOUT_FILENO, "\n", 1);
}
return (EOF);
}
return (EXIT);
