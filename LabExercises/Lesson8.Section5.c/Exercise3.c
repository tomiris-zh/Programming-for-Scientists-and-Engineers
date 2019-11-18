#include <stdio.h>

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    int n;
    scanf("%i", &n);
    printf("Enter an integer %i\n", n);
    do {
        int hex=n%16;
        n=n/16;
        printf("%i", hex);
    }
    while (n>0);
    return 0;
}
