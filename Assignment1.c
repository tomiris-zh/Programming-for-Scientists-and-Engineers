/*Number Guessing Game with extended description*/

#include <stdio.h>
#include<math.h>
#include<time.h>

int main() {

setvbuf(stdout, NULL, _IONBF, 0);
printf("WELCOME to the guessing game!\n");

int x, f=0, i=0, b, guessnumber, count=0;
char ch;
int a=9999;

srand(time(NULL));

do {
        x=rand()%(a+1);
        printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
        scanf(" %c", &ch);

        if (ch=='s') {
                f=0;
                count++;
            printf("The secret number is BETWEEN 0 AND %i. Guess: \n", a);
            scanf("%i", &guessnumber);

    do {
            i++;
            f++;
            if (guessnumber == x) {
            printf("Correct: You TOOK %i guesses!\n", f);
    break;
    }
    else if (guessnumber > x) {
        printf("Too HIGH! Guess:\n");
        scanf("%i", &guessnumber);
    }
    else if (guessnumber < x) {
        printf("Too LOW! Guess:\n");
        scanf("%i", &guessnumber);
            }}while(1);
        }

        else if (ch=='n') {
           printf("Enter a new MAXIMUM:\n");
           scanf ("%d", &b);
           a=b;
           continue;
        }
       else if (ch=='q') {
            if(i==0) {
                count=1;
            }
            printf("Thanks for playing! Your guess count AVERAGE %.1f \n", (float)i/count);
            break;
        }
        else {
            printf("Unrecognized command.\n");
        }
    }while (1);

return 0;
}
