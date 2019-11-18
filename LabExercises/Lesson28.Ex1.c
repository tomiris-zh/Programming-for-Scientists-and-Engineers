#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[12];
} student;

void selectionSortById(student *x[], int size) {

	 int i;
	 char arr[81];
     for (i = 0; i < size - 1; i++) {

          int j, mindex = i;
          for (j = i + 1; j < size; j++) {
               if (x[j]->id < x[mindex]-> id) {
                    mindex = j;
    }
          }

          int temp = x[i]->id;
          strcpy(arr, x[i]->name);
          x[i]->id = x[mindex]->id;
          strcpy(x[i]->name, x[mindex]->name);
          x[mindex]->id = temp;
          strcpy(x[mindex]->name, arr);
     }
}

_Bool nameCompare(char name1[], char name2[]) {

	int i = 0;
	do {
		if (name1[i] < name2[i]) {
			return 1;
		} else if (name1[i] > name2[i]) {
			return 0;
		}
		i++;
	} while (name1[i] != '\0' || name2[i] != '\0');

	return 0;
}

void insertionSortByName(student *x[], int size) {

	 int i, j;
	 char toInsert[81];
     for (i = 0; i < size; i++) {
     strcpy(toInsert, x[i]->name);
     int arr = x[i]->id;
     for (j = i; j >= 0; j--) {
     if (j == 0 || x[j-1] <= toInsert) {

     strcpy(x[j]->name, toInsert);
     x[j]->id = arr;
     break;

     } else {
     x[j]->id=x[j-1]->id;
     }
     }
     }
}

void printArray(student *x[], int size) {

	int i;
	for (i = 0; i < size; i++) {
		printf("%8i %12s \n", x[i]->id, x[i]->name);
	}
	printf("\n");
}

int main() {

	student *roster[8];

	// Opening the input file
	FILE *file = fopen("records.txt", "r");
	if (file == NULL) {
		printf("Cannot find file.");
		exit(1);
	}
	printf("File opened successfully.\n");

	// Reading the records into the roster from the file
	int i;
	for (i = 0; i < 8; i++) {
		roster[i] = malloc(sizeof(student));
		fscanf(file, "%i %s \n", &roster[i]->id, roster[i]->name);
	};
	fclose(file);

	// Printing out the roster, in the initial order
	printArray(roster, 8);

	// Sorting the array by id (hopefully)
	selectionSortById(roster, 8);

	// Printing out the roster, after sorting by id
	printArray(roster, 8);

	// Sorting the array by name (hopefully)
	insertionSortByName(roster, 8);

	// Printing out the roster, after sorting by name
	printArray(roster, 8);

	return 0;
}
