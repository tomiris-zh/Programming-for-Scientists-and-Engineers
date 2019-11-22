# Indicate if the positive number n is an ideal number.
# A number n is ideal if it is the sum over all its divisors (except n itself).
# Ex: 28 with divisors 1, 2, 4, 7, 14, 28 is ideal because 1+2+4+7+14=28.

#include <stdio.h>
#include <time.h>
#include <math.h>

_Bool isIdeal(int n);

int main () {
int x;
scanf("%d", &x);
if (isIdeal(x)){
printf("%d is ideal", x);
} else {
printf("%d is not ideal", x);
}
return 0;
}

_Bool isIdeal(int n){
int x = 0;
for (int i=1; i<n; i++){
if (n%i==0){
x+=i;
}}
if (x == n){
return 1;
}
else {
return 0;
}}
