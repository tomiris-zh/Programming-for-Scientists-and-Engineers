#include<stdio.h>

void reverse(char *fromStr, char *toStr)
{
    int count = 0;
    while (*fromStr != '\0') {
        count = count+1;
        fromStr++;
    }
    int i;
    *fromStr--;
    for (i=0; i<count; i++) {
        *toStr = *fromStr;
        printf("%c",*toStr);
        toStr++;
        fromStr--;
    }
}

int main(void) {

	char word1[] = "Hello";
	char word2[] = "Hi there";
	char word3[] = {'H', 'e', 'l', 'l', 'o', '\0', 'X'};
	char word4[] = "Hi";

	char result[50];

    // Test code for reverse
	reverse(word1, result);
	printf("Test 3.1 result: %s\n", result);
	reverse(word2, result);
	printf("Test 3.2 result: %s\n", result);
	reverse(word3, result);
	printf("Test 3.3 result: %s\n", result);

	return 0;
}
