#include <stdio.h>
#include <string.h>

int countFileLines(char filename[]) {
    char c;
    int i=0;
    FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Problem opening file.");
    return 1;
  }
  else {
  do {
    (c = fgetc(file));
    if (c == '\n') {
        i++;
    }
    } while(!feof(file));
    fclose(file);
	return i;
}
}

void readFile(char filename[], char twoDimArr[][50]) {
    int j=0;
    char arr[50];
    FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Problem opening file.");
    return 1;
  }
  else {
    while(!feof(file)) {
    fgets(arr, 50, file);
if (arr[strlen(arr)-1] == '\n'){
arr[strlen(arr)-1] = '\0';
}
strcpy(twoDimArr[j], arr);
j++;
}
fclose(file);
}
}

int isPalindrome(char str[]) {
    int x=0, y = strlen(str)-1;
    do {
        if (str[x++] != str[y--]) {
            return 0;
        }
    } while(x<y);
    return 1;
}

char *getPalindrome(char str[]) {
    char *ch;
	if (isPalindrome(str) == 1) {
		ch = "Is_Palindrome";
    }
	else {
		ch = "Not_Palindrome";
	}
	return ch;
}

int howManySubstrings(char subStr[], char str[]) {
    int len[strlen(str)];
    int count=0;
    for (count = 0; count<strlen(str); count++) {
            len[strlen(str)] = 0;
    if (subStr[0] == str[count] && subStr[1] == str[count+1] && subStr[2] == str[count+2]
        && !len[strlen(str)] && !len[strlen(str)+1] && len[strlen(str)+2]) {
            count++;
    len[strlen(str)] = len[strlen(str)+1] = len[strlen(str)+2] = 1;
        }
    }
    return count;
}

void checkSubstringPalindrome(char subStr[], char iStringData[][50], char oStringData[][50], int nrIOfileLines) {
    int x=0, y=0;
    sprintf(oStringData[x], "%s", subStr);
    while(y<nrIOfileLines) {
    sprintf(oStringData[x], "%s\t %i\t %s\n", iStringData[x], howManySubstrings(subStr, iStringData[y]),
            getPalindrome(iStringData[y]));
    y++;
    x++;
    }
}

void writeFile(char fileName[], char ssData[], char oStringData[][50], int nrIOfileLines) {
    FILE *fread = fopen(fileName, "r");
    FILE *file = fopen("oStrings.txt", "w");
	int x=0;
	if (fread == NULL || file == NULL) {
		printf("Problem opening file.");
		return 1;
	}
	else {
        fprintf(file, "%s", ssData);
    do {
    fprintf(file, "%s", oStringData[x]);
    x++;
    } while (x < nrIOfileLines);
	}
     fprintf(file, " ");
		fclose(fread);
		fclose(file);
    }

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	char file[81]="iStrings.txt";
	char subStrings[81] = "subStrings.txt";
	char oStrings[20] = "oStrings.txt";
	FILE *filename = fopen(oStrings, "w");
	if (filename == NULL) {
        printf("Problem opening file.");
        return 1;
	}
	int count1 = countFileLines(file);
	int count2 = countFileLines(subStrings);
	char out[count1][81];
	char subStr[count2][81];
	char in[count1][81];
	readFile(subStrings, subStr);
	readFile(file, in);
	int x=0;
	while (x<count2) {
    checkSubstringPalindrome(subStr[x], in, out, count1);
	writeFile(oStrings, subStr[x], out, count1);
        x++;
	}
	return 0;
}












