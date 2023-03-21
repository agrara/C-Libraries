#ifndef FIND_AND_REPLACE_H
#define FIND_AND_REPLACE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Finds and replaces a substring within a given string
 *
 * @params
 * - replacement substring
 * - substring to be replaced
 * - POINTER to the original string
 * - bool option - false for replacing only the first occurance, true for replace all occurances
 *
 * @return pointer to the modified string, NULL on failure
 */

char *findAndReplace(const char *, const char *, char **originalString, const bool);

#endif
