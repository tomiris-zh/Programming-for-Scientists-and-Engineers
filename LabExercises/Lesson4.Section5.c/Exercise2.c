

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
 int main (void) {

 setvbuf(stdout,NULL, _IONBF, 0);
 int m;
 scanf("%o", &m);
 printf("input octal number /n", m);
 printf("output decimal number %i /n", m);


 int l;
 scanf("%i", &l);
 printf("input decimal number /n", l);
 printf("output octal number %o /n", l);

 int k;
 scanf("%x", &k);
 printf("input hexadecimal number /n", k);
 printf("output decimal number %i /n", k);

 int c;
 scanf("%i", &c);
 printf("input decimal number/n", c);
 printf("output hexadecimal number %x/n", c);


 return 0;
 }

