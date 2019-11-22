# Extension of the first exercise: transpose the matrix (a) and store it in a new matrix (b)
# of dimensions C x R, and add 25 to each of its elements. Prints resulted (b).

#include<stdio.h>

int main() {

int i,j;
int a[13][13];

for (i=1; i<=12; i++) {
    for(j=1; j<=12; j++) {
        a[i][j] = i*j;
    }
}

int C,R;
int b[2][2];
for (C=1; C<=12; C++) {
    for (R=1; R<=12; R++) {
        b[C][R] = a[C][R]+25;
        printf("%4i", b[C][R]);
    }
    printf("\n");
}

return 0;
}
