#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef  struct  _Node{
         char strData[50];
         struct  _Node *next;
}Node;

void swap(char *str1, char *str2) {
 char *temp = str1;
 str1 = str2;
 str2 = temp;
}

void reverse(char *str) {
	int a, b = strlen(str) - 1;
	for (a = 0; b / 2 > a; a++)
		swap(&str[a], &str[b - a - 1]);
}

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

void readFile2(char filename[], char *ArrayPtr[]) {
    int j=0;
    FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Problem opening file.");
    return 1;
  }
  else {
    char twoDimArr[countFileLines(filename)][81];
    while(!feof(file) && countFileLines(filename)>j) {
    ArrayPtr[j] = (char*) malloc(81);
    fgets(ArrayPtr[j], 81, file);
    j++;
}
fclose(file);
}
}

void oneStrcpy(char *array1, char *array2) {
    int i=0;
    do {
        array1[i] = array2[i];
		i++;
    } while(strlen(array2)>i);
    array1[i-1] = '\0';
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
    int len[strlen(str)], count=0, len_int=0;
    while (strlen(str)>len_int) {
            len[strlen(str)] = 0;
            len_int++;
    }
    while (strlen(str)>len_int) {
    if (subStr[0] == str[len_int] && subStr[1] == str[len_int+1] && subStr[2] == str[len_int+2]
        && !len[len_int] && !len[len_int+1] && len[len_int+2]) {
            count++;
    len[len_int] = len[len_int+1] = len[len_int+2] = 1;
        }
    len_int++;
    }
    return count;
}

void freeLinkedlist(Node *head) {
    Node *prev = head->next;
	head->next = prev->next;
	while (head->next != NULL) {
		freeLinkedlist(head);
		break;
	}
	free(prev);
}

void printLinkedlist(Node *head) {
    FILE *file = fopen("oStrings.txt", "a");
	if (file == NULL) {
    printf("Problem opening file.");
    return 1;
    }
	if (head != NULL) {
		while (head != NULL) {
			printf("%s", head->strData);
			fprintf(file, "%s", head->strData);
			printf("%s", head->strData);
			head = head->next;
		}
		fprintf(file, "\n");
	}
	fclose(file);
}

void appendNode(Node **oLinkedList, char outputLine[]) {
    Node* temp = (Node*) malloc(sizeof(Node));
    char str[81];
	Node* one = *oLinkedList;
	strcpy(str, outputLine);
	strcpy(temp->strData, outputLine);
	temp->next = NULL;
	if ((*oLinkedList) == NULL) {
		(*oLinkedList) = temp;
		return 0;
	}
	while (one->next != NULL) {
		one = one->next;
        one->next = temp;
    }
}

void checkSubstringPalindrome2(char ssData[], char *iStringData[],  Node **oLinkedList, int nrIOfileLines) {
    int x;
	char s[81];
	for (x = 0; x < nrIOfileLines; x++) {
		oneStrcpy(s, iStringData[x]);
		strcat(s, "\t");
		int y = strlen(s), total = howManySubstrings(ssData, iStringData[x]) + 48;
		s[y] = total;
		s[y + 1] = '\0';
		strcat(s, "\t");
		strcat(s, getPalindrome(iStringData[x]));
		strcat(s, "\n");
		appendNode(oLinkedList, s);
	}
}

void writeFile2(char fileName[], char ssData[], Node **oLinkedList) {
        strcat(ssData, "\n");
        FILE *file;
		file = fopen(fileName, "a");
    if (file == NULL) {
        printf("Problem opening file.");
        return 1;
    }
	else {
        fprintf(file, "%s", ssData);
        printf("%s", ssData);
        fclose(file);
        printLinkedlist(*oLinkedList);
        printf("\n");
        freeLinkedlist(*oLinkedList);
	}
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
    char *s1[countFileLines("subStrings.txt")], *s2[countFileLines(
			"iStrings.txt")];
    Node *new = NULL;
    readFile2("subStrings.txt", s1);
	readFile2("iStrings.txt", s2);
    for (int x=0; x < countFileLines("subStrings.txt"); x++) {
		checkSubstringPalindrome2(s1[x], s2, &new, countFileLines("iStrings.txt"));
		writeFile2("oStrings.txt", s1[x], &new);
	}
	return 0;
}














