#include <stdio.h>

int main () {

setvbuf(stdout, NULL, _IONBF, 0);

int x;
int n=0;
printf("x:");
scanf("%i", &x);

while(x>1) {
    x=x/2;
    n++;
}
    printf("%i", n);
    return 0;
}
