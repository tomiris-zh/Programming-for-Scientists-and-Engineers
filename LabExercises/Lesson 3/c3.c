#include <stdio.h>
#include <math.h>
int main (void) {

double h=8;
double r=7;

printf("The surface area of a cone is %f", 3.14*r*(r+ sqrt(h*h + r*r)));
printf ("The volume of a cone is %f", (3.14*r*r*h)/3);
printf ("The area of a circular base of a cone is %f ", (3.14*r*r));


 return 0;
}
    double h = 3;
    double r= 3;
    double pi = 3.14;
    double A = pi*r*sqrt(h*h+r*r);
    double A1 = pi*r*r;
    double V = (A1*h)/3;
    printf("surface area: %f, area of the circular base %f, volume of the cone %f", A, A1, V);
}
