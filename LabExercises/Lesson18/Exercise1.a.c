#include <stdio.h>

double power(double x, int n){
    if (n == 0){
        return 1.0;
} else if (n>0) {
return power(x, n-1)*x;}
else {
    return power(1/x,-n);
}
}

int main () {
    double v;
    int j;
    for (j=-2; j<3; j++) {
      for (v=1.0; v<=5.0; v= v+0.5) {
        printf("%.1f^%i = %.3f \n", v, j, power(v, j));
      }
    }
    return 0;
    }
