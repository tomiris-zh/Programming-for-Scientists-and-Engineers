#include <stdio.h>

int main() {

int x, n, p=1, i;
printf("Enter a number and its power\n");
scanf("%d %d", &x, &n);

 for (i=1; i<=n; i++)
      p=p*x;
      printf("Result is %d", p);
 return 0;
}

