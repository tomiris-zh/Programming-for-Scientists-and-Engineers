#include <stdio.h>

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    int n,c=0;
    scanf("%i", &n);
    printf("Enter an integer %i\n", n);
    do {
        int oct=n%8;
        n=n/8;

        printf("+(%i*8^%i) ", oct,c);
        c++;
    }
    while (n>0);
    return 0;
}
