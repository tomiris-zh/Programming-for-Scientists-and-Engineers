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
