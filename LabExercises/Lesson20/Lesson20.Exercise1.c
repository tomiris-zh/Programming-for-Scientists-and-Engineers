#include <stdio.h>

void stringCopy(char fromStr[], char toStr[]) {

int i=0;
while(fromStr[i] != '\0') {
    toStr[i] = fromStr[i];
    i++;
}
toStr[i] = '\0';
printf("%s", toStr);
}

int main() {

char string1[] = {"New File"};
char string2[99];

stringCopy(string1, string2);
}
