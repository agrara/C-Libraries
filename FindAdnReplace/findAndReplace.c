#include "findAndReplace.h"

char *findAndReplace(char *replacementString, char *findString, char **originalString, const bool option)
{
	int changed = 0;
	char *findStrPtr = strstr(*originalString, findString);
	if (findStrPtr)
	{
		char *currentCharPtr = *originalString;
		size_t replacementStringLegth = strlen(replacementString);
		size_t findStringLength = strlen(findString);
		size_t originalStringLength = strlen(*originalString) + 1;
		char *returnString = (char *)(malloc((originalStringLength - findStringLength + replacementStringLegth) * sizeof(char)));
		if (!returnString)
		{
			return NULL;
		}

		int index = 0;
		while (currentCharPtr != findStrPtr && *currentCharPtr)
		{
			returnString[index] = *currentCharPtr;
			index++;
			currentCharPtr++;
		}

		for (int i = 0; i < replacementStringLegth; i++)
		{
			returnString[index] = replacementString[i];
			index++;
		}

		currentCharPtr += findStringLength;

		while (*currentCharPtr)
		{
			returnString[index] = *currentCharPtr;
			currentCharPtr++;
			index++;
			if (!(*currentCharPtr))
			{
				returnString[index] = 0;
			}
		}
		free(*originalString);
		*originalString = returnString;
		changed = 1;
	}
	if (changed && option)
	{
		findAndReplace(replacementString, findString, originalString, option);
	}
	return *originalString;
}