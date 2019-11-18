#include <stdio.h>
int main () {
    int x = 2;
    for(int n=1; n<=16; n++) {
        printf("%i power of 2 is %i\n", n, x);
        x=2*x;
    }
    return 0;
}
