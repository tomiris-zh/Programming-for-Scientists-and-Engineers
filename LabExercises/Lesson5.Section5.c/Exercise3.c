#include <stdio.h>

int main (void)
{
int x;
scanf("%i", &x);
int a=x/3600;
int b=(x%3600)/60;
int c=x-((a*3600)+(b*60));
printf("%i:%i:%i",a,b,c);
return 0;
}
