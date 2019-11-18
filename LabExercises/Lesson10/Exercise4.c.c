#include<stdio.h>

int main() {

setvbuf(stdout, NULL, _IONBF, 0);

    int count=0;
    int maxn = -999;
    char ch;
    printf("Input some characters: ");

    do {
        ch=getchar();
        if (ch == ' ')
        {
            if (count!=0) {
                if (maxn<count) maxn = count;
            }
            count = 0;
        }else
        count++;
    } while(ch !='\n');
    if (maxn<count-1) maxn = count-1;
     printf("%i", maxn);
    return 0;
}
