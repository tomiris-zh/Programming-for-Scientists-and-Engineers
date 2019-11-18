#include <stdio.h>
int main () {
    int x;
    for(x=2; x<=65536; x=2*x) {
        printf("%i\n", x);
    }
    return 0;
}
