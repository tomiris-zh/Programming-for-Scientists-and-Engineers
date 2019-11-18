// Loop that prints out the first 20 Fibonacci numbers.  
// Used separate variables to keep track of the values printed out from the previous two iterations.


#include <stdio.h>

int main () {

int a;
int x1=0, x2=1, nextTerm;
 printf("Fibonacci Numbers:");

while(a<=20) {
    printf("%d\n", x1);
    nextTerm=x1+x2;
    a++;
    x1=x2;
    x2=nextTerm;
}
    return 0;
}
