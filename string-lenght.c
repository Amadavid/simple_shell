#include "sheell.h"

/**
 * string_length - Calculate the length of a given string, including the
 * null-terminating character.
 *
 * @str_to_measure: The string for which length is to be calculated.
 *
 * Return: The length of the input string, including the null terminator.
 **/
int string_length(char *str_to_measure)
{
    int char_count = 0; // Initialize a counter for characters in the string.

    // Iterate through the string until the null terminator is encountered.
    while (str_to_measure[char_count] != '\0')
    {
        char_count++; // Increment the character count.
    }

    return (char_count + 1); // Return the total character count, including the null terminator.
}
