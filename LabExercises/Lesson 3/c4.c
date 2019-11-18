#include <stdio.h>
#include <math.h>
int main (void) {
    double labs = 100;
    double assesment = 100;
    double quiz = 100;
    double fnl = 100;
    double grade = labs*0.1 + assesment*0.2 + quiz*0.35 + fnl*0.35;
    printf("My overall grade is %f", grade);
}
