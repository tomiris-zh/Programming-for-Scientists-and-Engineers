#include<stdio.h>

_Bool areEqual(char *str1, char *str2) {
    int count1=0,count2=0;
	do {
		count1=count1+1;
		str1++;
	} while (*str1!='\0');
	do {
		count2=count2+1;
		str2++;
	} while (*str2!='\0');

	if (count1==count2){
		printf("Strings are equal.");
	}
	else {
		printf("Strings are different.");
	}
}


int main(void) {

	char word1[] = "Hello";
	char word2[] = "Hi there";
	char word3[] = {'H', 'e', 'l', 'l', 'o', '\0', 'X'};
	char word4[] = "Hi";

// Test code for areEqual
	printf(" Test 2.1 result: %i\n", areEqual(word1, word2));
	printf(" Test 2.2 result: %i\n", areEqual(word1, word3));
	printf(" Test 2.3 result: %i\n", areEqual(word2, word4));
	printf(" Test 2.4 result: %i\n", areEqual(word4, word2));

	return 0;
}
