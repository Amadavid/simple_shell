#include "sheell.h"

/**
* putcharr - writes the character to a specified file descriptor
*
* @fd: The file descriptor to be given when writing bytes
*
* @character: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set.
*/
int putcharr(char character, int fd)
{
/* This function is used to write characters to the console.*/
return (write(fd, &character, 1));
}
