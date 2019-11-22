# Copies contents of an input file, and writes them to another file.
# The input and output file names should be provided by user at the beginning.

#include <stdio.h>

int main() {

 FILE *infile;
 FILE *outfile;
 char inname[81];

 printf("Enter the in filename:");
 scanf("%s", inname);

 printf("Enter the out filename:");
 char outname[81];
 scanf("%s", outname);

 infile  = fopen(inname, "r");
 outfile = fopen(outname, "w");

 if (infile == NULL || outfile == NULL) {
 printf("Problem opening files.");
 return 1;
 }

 printf("Files opened successfully.\n");

 char ch;
 while (!feof(infile)) {
        fscanf(infile, "%c", &ch);
		fprintf(outfile, "%c", ch);
 }

printf("\nContents copied to %s", outname);

 fclose(infile);
 fclose(outfile);

    return 0;
}
