#include <stdio.h>

int addSubarray (int x[], int from, int to) {
    int i, sum=0;
    if (from==to) {
        return x[from];}
    else {
        return addSubarray(x, from+1, to)+x[from];
    }
}

int main () {
    int arr[8] = {4, 3, -2 , 7, 2, 5, -1, 0};
        printf("sum = %i \n", addSubarray(arr, 0, 7));
        printf("sum = %i \n", addSubarray(arr, 1, 5));
        printf("sum = %i \n", addSubarray(arr, 4, 6));
    return 0;
    }
