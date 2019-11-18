#include <stdio.h>
#include <math.h>
int main(void)
{
double x;
scanf("%lf",&x);
double sin=x-(pow(x, 3)/(3*2))+((pow(x, 5))/(5*4*3*2));
printf("sin(x) is: %f", sin);
return 0;
}
