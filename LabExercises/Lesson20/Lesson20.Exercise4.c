#include <stdio.h>

void concat(char str1[], char str2[], char resultStr[]) {
int i=0, k=0;
while(str1[i] != '\0') {
    resultStr[i] = str1[i];
    i++;
}
while(str2[k] != '\0') {
     resultStr[i+k] = str2[k];
     k++;
}
resultStr[i+k] = '\0';
}

int main() {

char string1[] = { "Programming " };
char string2[] = { "assignment" };
char string3[99];

concat (string1, string2, string3);

printf("%s\n", string3);

return concat;
}
