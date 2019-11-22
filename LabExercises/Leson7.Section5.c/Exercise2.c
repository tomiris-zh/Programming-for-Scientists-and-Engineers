// Loop for a positive integer n, finds the biggest integer k for which n ≥ 2^k -> Essentially finding the integer log base-2 of n. 
// Without usage of pow, log2, or any functions from math.h!
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
