#include <stdio.h>

double power(double x, int n) {
	if (n == 0) {
		return 1.0;
	}
	if (n < 0) {
        return power(1/x, -n);
    }
	if (n % 2 == 0){
		double a = power(x, n/2);
		return a*a;
	} else {
        return power(x, n-1) * x;
	}
}

int main () {
	double v;
	int j;
	for (j = -2; j < 3; j++) {
		for (v = 1.0; v <= 5.0; v = v + 0.5) {
			printf ("%.1f^%i = %.3f\n", v, j, power(v, j));
		}
	}
	return 0;
}
