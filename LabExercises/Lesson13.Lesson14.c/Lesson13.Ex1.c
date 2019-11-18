#include<stdio.h>

int main() {

int i,j;
int arr[13][13];

for (i=1; i<=12; i++) {
    for(j=1; j<=12; j++) {
        arr[i][j] = i*j;
        printf("%4i", arr[i][j]);
    }
    printf("\n");
}
return 0;
}
