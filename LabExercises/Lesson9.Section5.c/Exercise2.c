#include <stdio.h>

int main(void) {
setvbuf(stdout, NULL, _IONBF, 0);
int n, i, j, k = 2;
printf ("Enter an integer:");
scanf("%i", &n);

for (int i = 1; i <= n;k++) {
    for ( j = 2; j < k; j++) {
        if (k%j== 0) {
            break;
}}
if (j == k) {
printf("%02d",k);
i++;
}
if (i%5==1){
    printf(" \n");
}
}
return 0;}


