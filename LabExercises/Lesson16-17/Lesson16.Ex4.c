#include <stdio.h>

int SumofDigits(int n){
int x;
if(n==0){
return 0;
}
else{
    x = n%10 + SumofDigits(n/10);
}
return x;
}

int main () {
setvbuf(stdout, NULL, _IONBF, 0);
int a, sum;
printf("Enter positive number: \n");
scanf("%i", &a);
sum = SumofDigits(a);
printf("Sum of digits is %i", sum);
return 0;
}
