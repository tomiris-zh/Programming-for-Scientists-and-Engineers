#include<stdio.h>

void concatenate(char *str1, char *str2, char *resultStr) {
	while (*str1!='\0') {
		*resultStr = *str1;
		printf("%c", *resultStr);
		str1++;
		resultStr++;
	}
	while (*str2!='\0') {
		*resultStr = *str2;
		printf("%c", *resultStr);
		str2++;
		resultStr++;
	}
}

int main(void) {

	char word1[] = "Hello";
	char word2[] = "Hi there";
	char word3[] = {'H', 'e', 'l', 'l', 'o', '\0', 'X'};
	char word4[] = "Hi";

	char result[50];

	// Test code for concatenate
	concatenate(word1, word2, result);
	printf("Test 4.1 result: %s\n", result);
	concatenate(word3, word4, result);
	printf("Test 4.2 result: %s\n", result);
	concatenate(word1, word1, result);
	printf("Test 4.3 result: %s\n", result);

	return 0;
}
