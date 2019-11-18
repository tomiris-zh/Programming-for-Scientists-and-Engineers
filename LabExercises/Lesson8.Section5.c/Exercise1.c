#include <stdio.h>

int main() {
     setvbuf (stdout, NULL, _IONBF, 0);
     int a;

     do {
             printf("Enter an integer: ");
        scanf ("%i", &a);
        printf("The number squared is: %i \n", a*a);
     } while(a>=0);
     return 0;

}
