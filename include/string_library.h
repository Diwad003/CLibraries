#ifndef STRING_LIBRARY_HEADER
#define STRING_LIBRARY_HEADER

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SPLIT_STRING_SIZE 256

/* 
* Description: Make a whole string into lowercase

* Input: A string and its size

* Output: Makes string (char*) into lowercase
*/
int makeStringLowercase(char* string, int sizeOfString);

/* 
* Description: Splits a string into parts which is between the delimiter, it also allocates the string matrix in heap

* Input: a String, the stringsize, delimitor, and a pointer to its output

* Output: a string which has been split, allocated the string matrix in heap
*/
char** splitString(char input[], char delimit[], int* outputStringSize);

#endif 