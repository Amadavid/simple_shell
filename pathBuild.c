#include "sheell.h"


/**
* pathBuild - Concatenate multiple strings into a new string, separated by a colon.
*
* @numStrings: The number of strings to concatenate.
* @...: The variable number of string arguments to concatenate.
*
* Return: A pointer to a new dynamically allocated string containing the concatenated strings,
* separated by a colon.
*/
char *pathBuild(int numStrings, ...)
{
va_list args;
char *result = NULL;
int totalLength = 0;

// Calculate the total length of the concatenated string
va_start(args, numStrings);
for (int i = 0; i < numStrings; i++) 
{
char *str = va_arg(args, char *);
totalLength += strlen(str);
}
va_end(args);

// Allocate memory for the concatenated string
result = (char *)malloc(totalLength + numStrings + 1);

if (result) 
{
// Concatenate the strings, separated by a colon
va_start(args, numStrings);

result[0] = '\0'; // Initialize the result string

for (int i = 0; i < numStrings; i++) 
{
char *str = va_arg(args, char *);
strcat(result, str);

if (i < numStrings - 1) {
strcat(result, ":");
}
}
}

va_end(args);

return (result);
}
