#include <stdio.h>

void reverse(char fromStr[], char toStr[]) {

int i=0, k=0;
int count=0;
while(fromStr[i] != '\0') {
    count = count+1;
    i++;
}
while(fromStr[k] != '\0') {
    toStr[i-1] = fromStr[k];
    k++;
    i--;
}
toStr[k] = '\0';
printf("%s", toStr);
}

int main() {

char string1[] = {"Nice to meet"};
char string2[99];

reverse(string1, string2);
}
