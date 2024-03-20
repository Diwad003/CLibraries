#include "string_library.h"

int makeStringLowercase(char *string, int sizeOfString)
{
    for (size_t i = 0; i < sizeOfString; i++)
    {
        string[i] = tolower(string[i]);
    }
    return 0;
}

char** splitString(char input[], char delimit[], int* outputStringSize)
{
    int i = 0, count = 0;
    char *p = strtok(input, delimit);
    char *array[SPLIT_STRING_SIZE];
    char ** outputString;

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok(NULL, delimit);
        count++;
    }

    outputString = calloc(count, sizeof(char*));
    for (i = 0; i < count; i++) 
    {
        if (strcmp(array[i], "\n") != 0)
        {
            outputString[i] = calloc(strlen(array[i]), sizeof(char));
            strcpy(outputString[i], array[i]);
        }
    }

    *outputStringSize = count;
    return outputString;
}
