// Encryption and Decryption of File: used 'key.254' file
// More explanation in 'HW2Fall2018-fix.pdf' and 'HW2Fall2018-Example-Updated.pdf' files

#include<stdio.h>
#include<string.h>

void encrypt (FILE *fin, FILE *fout, char subarr[], char pass[] ) {
 char ch1, c;
    int i=0;
do {
    ch1 = getc(fin);
    if (ch1 == EOF){
        break;
    }
    if(i == strlen(pass)) {
        i=0;
    }
    c = subarr[(ch1+pass[i])%255];
    i++;
    putc(c, fout);
} while(ch1!=EOF);
fclose(fin);
}

int index (char c, char arr[]) {
    int k=0;
 do {
    if (arr[k] == c) {
        return k;
    }
    k++;
}  while(k < 254);
}

void decrypt (FILE *fin, FILE *fout, char subarr[], char pass[] ) {
    char ch2, m;
    int j=0;
 do {
    ch2 = getc(fin);
    if (ch2 == EOF){
        break;
    }
    m = ((index(ch2, subarr) - pass[j] + 255)%255);

    j++;
    if(j == strlen(pass)) {
        j=0;
    }

    putc(m, fout);
 } while(ch2!=EOF);
}

void subarray(unsigned char subarr[]) {
    FILE *output;
    output = fopen("key.254", "r");
    int n=0;
do {
    subarr[n]= getc(output);
    n++;
} while(n < 254);
fclose(output);
}

int main() {
    printf("WELCOME to the encryption service.\n");
    printf("ENTER your password\n");
char password[255], subarr[254], input1[255], input2;
scanf("%s", password);
FILE *efile, *dfile;
int i=5;
do {
    printf("MENU: <e>ncode, <d>ecode, or <q>uit\n");
    char infile[255], outfile[255];
    scanf("%s", input1);
    input2=input1[0];
    subarray(subarr);
    if (input2 == 'e'){
        FILE *efile, *dfile;
        printf("ENTER a file to encrypt\n");
        scanf("%s", infile);
        efile = fopen( infile, "r" );
        if (efile == NULL) {
			printf("CANNOT open %s\n", infile);
			continue;
        }
        printf("ENTER a filename for the encrypted file.\n");
        scanf("%s", outfile);
        dfile = fopen(outfile, "w");
        if (dfile == NULL) {
            printf("CANNOT open %s\n", outfile);
			continue;
        }
        encrypt(efile, dfile, subarr, password);
        fclose(efile);
        fclose(dfile);
    } else if (input2 == 'q'){
        i = 1;
        break;
} else if (input2 == 'd'){
            FILE *efile, *dfile;
            printf("ENTER a file to decrypt\n");
			scanf("%s", infile);
			efile = fopen( infile , "r" );
			if (efile == NULL) {
			printf("CANNOT open %s\n", infile);
			continue;}
			printf("ENTER a filename for the decrypted file.\n");
			scanf("%s", outfile);
			dfile = fopen(outfile, "w");
			if (dfile == NULL) {
			printf("CANNOT open %s\n", outfile);
			continue;
			}
			decrypt(efile, dfile, subarr, password);
			fclose(dfile);
			fclose(efile);
			} else {
                printf("UNRECOGNIZED %s\n", input2);
            }
    }
while(i>2);
printf("BYE!");
return 0;
}


