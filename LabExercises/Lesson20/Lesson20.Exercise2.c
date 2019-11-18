#include <stdio.h>

_Bool areEqual(char str1[], char str2[]) {

int i=0, j=0;
int count1=0, count2=0;
while (str1[i] != '\0') {
        count1 = count1+1;
        i++;
}
while (str2[j] != '\0') {
        count2 = count2+1;
        j++;
}
    if (count1 == count2) {
        int k=0;
        while(str1[k] != '\0' && str2[k] != '\0') {
            if (str1[k] != str2[k]) {
                    return 1;
            }
        k++;
        }
    }else return 1;
    return 0;
}

int main() {

 char str1[] = "Welcome to NY city";
 char str2[] = "Welcome to NY city";

    if(areEqual(str1, str2) == 0){
        printf("Strings are equal!");
    }
    else{
        printf("Strings are not equal!");
    }

return 0;

 }
