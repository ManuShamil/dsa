#include <stdio.h>
#include <string>

const int STRING_SIZE_MAX = 512;

char* longestCommonPrefix(char** strs, int strsSize) {
	
	char* longestPrefix = (char*)malloc(STRING_SIZE_MAX * sizeof(char));

	int prefixHeader = 0;
	char currChar = NULL;
	int exitFlag = 0;

	while (!exitFlag) {


		for (int i = 0; i < strsSize; i++) {

			if (strs[i][prefixHeader]== '\0') {
				exitFlag = 1;
				break;
			}

			if (currChar == NULL)
				currChar = strs[i][prefixHeader];

			if (strs[i][prefixHeader] != currChar) {
				exitFlag = 1;
				break;
			}


		}

		if (exitFlag) break;

		longestPrefix[prefixHeader++] = currChar;

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