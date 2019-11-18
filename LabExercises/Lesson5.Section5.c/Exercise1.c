#include <stdio.h>
#include <math.h>

int main (void)
{
double a;
double b;
double c;
scanf("%lf %lf %lf",&a,&b,&c);
double d=pow(b, 2)-4*a*c;
double x1=(-b-sqrt(d))/2*a;
double x2=(-b+sqrt(d))/2*a;
printf("Roots: %f, %f", x1, x2);
return 0;
}
