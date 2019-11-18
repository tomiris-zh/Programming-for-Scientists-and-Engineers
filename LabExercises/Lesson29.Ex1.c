#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char name[12];
} student;

void bubbleSortById(student *x[], int size) {

	int i, j;

 for (i = 0; i < size - 1; i++) {

 for (j = 0; j < size - 1 - i; j++) {

 if (x[j] > x[j + 1]) {

 int temp = x[j + 1];
 x[j + 1] = x[j];
 x[j] = temp;
 }
 }
 }
}

int partitionByName(student *x[], int first, int last) {

	 int pivot = first;

 int up = first, down = last;
 while (up < down) {

 while (x[up] <= x[pivot] && up < last) {
 up++;
 }
 while (x[down] > x[pivot]) {
 down--;
 }
 if (up < down) {
 int temp = x[up];
 x[up] = x[down];
 x[down] = temp;
 }
 }

 int temp2 = x[pivot];
 x[pivot] = x[down];
 x[down] = temp2;

	return 0;
}

void quicksortByName(student *x[], int first, int last) {

    if (first < last) {
 int pivIndex = partitionByName(x, first, last);
 quicksortByName(x, first, pivIndex-1);
 quicksortByName(x, pivIndex+1, last);
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
	bubbleSortById(roster, 8);

	// Printing out the roster, after sorting by id
	printArray(roster, 8);

	// Sorting the array by name (hopefully)
	quicksortByName(roster, 0, 7);

	// Printing out the roster, after sorting by name
	printArray(roster, 8);

	return 0;
}
