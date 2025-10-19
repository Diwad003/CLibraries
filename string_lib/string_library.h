#ifndef STRING_LIBRARY_HEADER
#define STRING_LIBRARY_HEADER

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SPLIT_STRING_SIZE 256

/**
 * Converts all uppercase characters in the given string to lowercase.
 *
 * @param string Pointer to the null-terminated string that will be modified in place.
 * @param sizeOfString The length of the string to be processed (excluding the null terminator).
 * @return Returns 0 upon successful completion.
 *
 * This function iterates through each character in the input string, converting
 * any uppercase letters to their lowercase equivalents using the `tolower` function.
 * The string is modified in place, and the function always returns 0 to indicate
 * successful execution.
 */

int makeStringLowercase(char* string, int sizeOfString);

/**
 * Splits the input string into tokens based on the specified delimiters.
 *
 * @param input The string to be split. This string will be modified by the `strtok` function.
 * @param delimit A string containing the delimiters used to split the input string.
 * @param outputStringSize Pointer to an integer where the number of tokens will be stored.
 * @return A pointer to an array of strings, where each string is a token from the input string.
 *
 * Memory Management:
 * - The caller must free the memory allocated for each string in the returned array.
 * - The caller must also free the memory allocated for the array of strings itself.
 *
 * Limitations:
 * - The size of the `array` is defined by `SPLIT_STRING_SIZE`, which should be sufficient
 *   to handle the maximum number of tokens expected. If `SPLIT_STRING_SIZE` is too small,
 *   the function may not handle more tokens than this size correctly.
 */
char** splitString(char input[], char delimit[], int* outputStringSize);

/**
 * Extracts a substring from `str` that is between two specified separators.
 *
 * @param str The input string from which to extract the substring.
 * @param firstSeparator The character marking the start of the substring to extract.
 * @param endSeparator The character marking the end of the substring to extract.
 * @param output Buffer to hold the extracted substring. It must be large enough to store the resulting string plus a null terminator.
 *
 * Note:
 * - The function does not handle cases where `str` or `output` are `NULL`. It is the caller's
 *   responsibility to ensure that `output` is properly allocated and `str` is a valid string.
 * - The behavior is undefined if `firstSeparator` is not found or if `endSeparator` is found
 *   before `firstSeparator`.
 *
 * Example:
 *   Input: str = "abc<value>xyz", firstSeparator = '<', endSeparator = '>'
 *   Output: "value"
 */
void ExtractBetweenValue(const char* str, const char firstSeparator, const char endSeparator, char* output);

#endif 