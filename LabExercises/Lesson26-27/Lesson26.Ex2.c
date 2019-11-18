#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int rain;
	int temp;
	int wind;
	double avgw, avgt;
} weather;

typedef struct struct_first {
	double value;
	struct struct_first* link;
} first;

void printList(first *node) {
	if (node != NULL) {
		printf("%lf ", node->value);
		printList(node->link);
    }
}

void freeAll(first *node) {
    if (node != NULL) {
        freeAll(node->link);
        printf("Freeing up %c \n", node->value);
        free(node);
    }
}

int main() {
	weather *first = NULL;
	weather *prev = NULL;
	weather *w;
	FILE *infile;
	infile = fopen ("astana.txt", "r");
	int ra;
	double te, wi;
    do {
    w = malloc(sizeof(weather));
    fscanf(infile, "%i %lf %lf", &ra, &te, &wi);
    w->rain = ra;
    w->temp = te;
    w->wind = wi;
    w->link = NULL;
        if (first == NULL) {
			first = w;
			prev = first;
		} else {
			prev->link = w;
		}
		prev = w;
        } while (feof(infile));
        return 0;
}

