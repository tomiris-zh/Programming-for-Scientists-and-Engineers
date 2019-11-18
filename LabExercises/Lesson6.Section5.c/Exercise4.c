#include <stdio.h>

int main() {

int NUM;
int i, j;
int star, plus;

NUM =5;
plus =5;
star =0;

 for (i=0; i<6; i++) {
    for (j=0; j<plus; j++)
        printf("+");
    for (j=1; j<=star; j++)
        printf("*");
    plus--;
    star++;
    printf("\n");
 }
 return 0;
}

