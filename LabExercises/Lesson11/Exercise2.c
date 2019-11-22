# Substitutes words found in the file values.txt in for the ‘$’ characters
# found in story.txt, and prints the result to the console window.

#include <stdio.h>

int main() {

FILE *infile;
FILE *outfile;

infile = fopen("values.txt", "r");
outfile = fopen("story.txt", "r");

if (infile == NULL || outfile == NULL) {
 printf("Problem opening files.");
 return 1;
 }

 while (!feof(outfile)) {
        char ch1[100];
        fscanf(infile, "%s", ch1);
    while(!feof(outfile)) {
        char ch2;
		fscanf(outfile, "%c", &ch2);
    if (ch2 == '$') {
        printf("%s", ch1);
        break;
    } else {
    printf("%c", ch2);
    }
 }
 }

 fclose(infile);
 fclose(outfile);

    return 0;
}
