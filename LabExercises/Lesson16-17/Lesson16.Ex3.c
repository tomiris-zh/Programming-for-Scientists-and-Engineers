# Indicate whether given integer n is prime or not, assuming n>1.

#include <stdio.h>
#include <time.h>
#include <math.h>

_Bool isPrime(int n){
for (int i=n-1; i>1; i--){
if (n%i==0){
return 0;}}
return 1;
}

int main () {
int x;
scanf("%d", &x);
if(isPrime(x)){
printf("%d is prime", x);
} else {
printf("%d is not prime", x);
}
return 0;
}
