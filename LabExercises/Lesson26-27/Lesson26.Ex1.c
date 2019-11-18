#include <stdlib.h>
#include <stdio.h>

typedef struct _doubleNode {
	char value;
	struct _doubleNode* link;
} doubleNode;

void printList(doubleNode *node) {
	if (node != NULL) {
		printf("%c ", node->value);
		printList(node->link);
    }
}

void reverse(doubleNode *node) {
	if (node != NULL) {
		reverse(node->link);
		printf("%c ", node->value);
    }
}

void freeAll(doubleNode *node) {
    if (node != NULL) {
        freeAll(node->link);
        printf("Freeing up %c \n", node->value);
        free(node);
    }
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	int k=0;
    doubleNode *first = NULL;
	doubleNode *prev = NULL;
    do {
		doubleNode *newNode = malloc(sizeof(doubleNode));
        newNode->value = 'a' + k;
		newNode->link = NULL;
        if (first == NULL) {
			first = newNode;
		} else {
			prev->link = newNode;
		}
        prev = newNode;
		k++;
        } while (k<=25);
        printList(first);
        printf("\n");
        reverse(first);
        printf("\n");
        freeAll(first);
        return 0;
}

