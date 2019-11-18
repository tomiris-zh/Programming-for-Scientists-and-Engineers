#include<stdio.h>

int main() {

setvbuf(stdout, NULL, _IONBF, 0);

    int count=0;
    char ch;
    printf("Input some characters: ");

    do {
        ch=getchar();
        if (ch == ' ')
        {
            if (count!=0)
            printf("%d\n", count);
            count = 0;
        }else
        count++;
    } while(ch !='\n');
     printf("%i", count-1);
    return 0;
}


/*char ch;
printf("Input some characters: ");
int count=0;

do {
    ch=getchar();
    if (ch==' '){
            if (count==0) {
                continue;
            }
    printf("%i", count);
    count = 0;
    }
    else{
    count++;
    }

} while(ch!='\n');

printf("%i", count-1);
return 0;

}*/
