#include <stdio.h>

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    char ch;
    printf("Enter the text:");
    do {
        scanf("%c", &ch);
        if(ch>=97 && ch<=122 ) {
        ch=ch-32;
        }
        printf("%c", ch);

    } while(ch!='\n');

    return 0;
}
