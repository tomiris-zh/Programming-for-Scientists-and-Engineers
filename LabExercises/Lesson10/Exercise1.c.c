#include <stdio.h>

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    scanf("");
    int count=0;
    char ch;

    do {
        ch=getchar();
            if(ch=='a' || ch=='A') {
        count++;
            }
    } while(ch !='\n');
     printf("%i", count);
    return 0;
}
