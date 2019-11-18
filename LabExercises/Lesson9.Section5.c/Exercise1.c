#include <stdio.h>

int main() {

setvbuf(stdout, NULL, _IONBF, 0);

int n;

printf("Enter an integer: ");
scanf("%i", &n);

if (n%2==0) {
    printf("%i is even", n);
}
else {
    printf("%i is odd", n);
}
return 0;
}
