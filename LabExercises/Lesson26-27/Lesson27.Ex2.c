#include <stdlib.h>
#include <stdio.h>

double func(double k) {
	double x1 = -255;
	double x2= 255;
	double y;
    while (x2 >= x1) {
		double x = (x1 + x2)/2;
		y = -2*x*x*x-x+2;
        if (k == y) {
	    	y = -2*x*x*x-x+2;
	    	return x;
	    }
	    else if (k > y) {
	    	x2 = x + 1;
	    }
	    else {
	    	x1 = x - 1;
	    }
	}
    return y;
}

int main() {
	printf("Test zero: %lf \n", func(0));
    return 0;
}
