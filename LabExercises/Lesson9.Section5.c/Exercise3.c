#include <stdio.h>

int main() {

setvbuf(stdout, NULL, _IONBF, 0);

int n,i,m=1;

printf("Enter an integer: ");
scanf("%i", &n);

for (i=1; i<=n; i++) {
    if (i%2==1) {
        m=m*i;
    }
    }
    printf("Product of odd numbers is %i", m);
return 0;
}
