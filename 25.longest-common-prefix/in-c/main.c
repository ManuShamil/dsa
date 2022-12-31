#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int STRING_SIZE_MAX = 512;

char* longestCommonPrefix(char** strs, int strsSize) {

	char* longestPrefix = (char*)malloc(STRING_SIZE_MAX * sizeof(char));

	int seekIndex = 0;
	int exitFlag = 0;

	while ( !exitFlag ) {

		char val = *(strs[0] + seekIndex);
		for ( int i=1; i<strsSize; i++ ) {
			char *pos = strs[i] + seekIndex;

			if ( pos == NULL || val != *pos ) {
				exitFlag = 1;
				break;
			}
		}

		if ( exitFlag ) break;

		longestPrefix[ seekIndex ] = val;

		seekIndex++;
	}


	return longestPrefix;
}

int main() {


	const int arraySize = 2;
	char** stringArray = (char**)malloc(arraySize * sizeof(char*));

	for (int i = 0; i < arraySize; i++)
		stringArray[i] = (char*)malloc(STRING_SIZE_MAX * sizeof(char));

	strcpy(stringArray[0], "flow");
	strcpy(stringArray[1], "flight");

	char* longestPrefix = longestCommonPrefix(stringArray, STRING_SIZE_MAX);

	printf("Longest Prefix: %s", longestPrefix);

	return 0;
}