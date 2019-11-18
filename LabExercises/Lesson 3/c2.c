// Measurement conversion.  Declare a variable of type double that stores a length value in meters, and assign it some value.  
// Declare several other variables that store this same length converted into centimeters, 
// myriameters, inches, miles, and furlongs, and output all variable values with suitable messages to the console window.

#include <stdio.h>
int main (void) {
    int m = 1;
    int cm = 100;
    int mr= 10000 ;
    double in = 39.07;
    double miles = 0.0006214;
    double furlong = 0.004972;
    printf("In 1 meter centimeters %d, myriameters %d, inches %f, miles %f, furlongs %f", cm, mr, in, miles, furlong);
}
