#include "sheell.h"

/**
* tokenizeString - Tokenize a string into an array of tokens
*
* @inputStr: The input string to be tokenized, including command line arguments if any
* @delimiter: The delimiter character(s) used for tokenization
*
* Return: An array of tokens
*/
char **tokenizeString(char *inputStr, char *delimiter)
{
char **tokensArray = NULL;   // Array to store the tokens
int tokenCount = 0;         // Count of tokens found
int tokensFound = 0;        // Counter for tokens found
char *token = NULL;         // Temporary storage for a token
int inputLength = 0;        // Length of the input string

inputLength = getStringLength(inputStr);  // Calculate the length of the input string
token = allocateMemory(inputLength);      // Allocate memory for the temporary token

// Copy the input string to the temporary token
copyString(token, inputStr);

// Count the number of tokens in the input string
tokenCount = countTokens(token, delimiter);

// Free the temporary token
// Allocate memory for the tokensArray
tokensArray = allocateTokenArray(tokenCount);

// Tokenize the input string
token = strtok(inputStr, delimiter);
while (token != NULL)
{
// Store the token in the tokensArray
tokensArray[tokensFound++] = copyString(token, NULL);

// Get the next token
token = strtok(NULL, delimiter);
}

// Set the last element of the tokensArray to NULL
tokensArray[tokensFound] = NULL;

// Free the temporary token
freeMemory(token);

return tokensArray;
}
