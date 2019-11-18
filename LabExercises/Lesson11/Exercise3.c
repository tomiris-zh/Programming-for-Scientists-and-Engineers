#include <stdio.h>
#include <stdlib.h>
int main() {

FILE *infile;
FILE *outfile;

char x[100];
char y[100];

printf("Enter input filename:");
scanf("%s", x);
printf("Enter output filename:");
scanf("%s", y);

infile = fopen(x, "r");
outfile = fopen(y, "w");

if (infile == NULL || outfile == NULL) {
 printf("Problem opening files.");
 return 1;
 }

 char ch;
 while(!feof(infile)) {
    ch = fgetc(infile);
    putc(ch,outfile);
 }

 fclose(infile);
 fclose(outfile);
 return 0;
}
