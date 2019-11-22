# Structure <student> with defined parameters. Calculate grades, and give information about student with final grade percentage for the course.

#include<stdio.h>

typedef struct {
    int id;
    char gender;
    double grade1;
    double grade2;
    double grade3;
    double finalGrade;
} student;

int main() {

    setvbuf(stdout, NULL, _IONBF, 0);

    student initializer;

    printf("Enter student ID: \n");
    scanf("%i", &initializer.id);

    if (initializer.id>999999 || initializer.id<100000) {      /*as ID includes no more than 6 digits*/
        printf("Wrong ID number");
    }
    else {
    printf("What is the gender of the student (m/f)?\n");
    scanf(" %c", &initializer.gender);

    if (initializer.gender == 'm' || 'M') {
       printf("Man\n");
    }
    else if (initializer.gender == 'f' || 'F') {
        printf("Female\n");
    }

    printf("What is the first grade? \n");
    scanf(" %d", &initializer.grade1);

    if (initializer.grade1 < 0.0 || initializer.grade1 > 100.0) {
                    printf("Wrong grade!!!");}

    printf("What is the second grade? \n");
    scanf(" %d", &initializer.grade2);

    if (initializer.grade2 < 0.0 || initializer.grade2 > 100.0) {
                    printf("Wrong grade!!!");}

    printf("What is the third grade? \n");
    scanf(" %d", &initializer.grade3);

    if (initializer.grade3 < 0.0 || initializer.grade3 > 100.0) {
                    printf("Wrong grade!!!");}


    initializer.finalGrade = (initializer.grade1 + initializer.grade2 + initializer.grade3)/3;

    if (initializer.gender == 'm' || 'M') {
       printf("Srudent ID: %i, Gender: Man, Final Grade is: %d", initializer.id, initializer.finalGrade);
    }
    else if (initializer.gender == 'f' || 'F') {
        printf("Srudent ID: %i, Gender: Female, Final Grade is: %d", initializer.id, initializer.finalGrade);
    }
    }


return 0;
}
