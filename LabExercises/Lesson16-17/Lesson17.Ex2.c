#include <stdio.h>

double maxVal(int len, double arr[100][100]){
double maximum = arr[0][0]s;
for (int i=0; i<len; i++){
    for (int j=0; j<len; j++){
    if (maximum<arr[i][j]){
        maximum = arr[i][j];
}}}
return maximum;
}

int main () {
int n;
scanf("%d", &n);
double array[100][100];
for (int i=0; i<n; i++){
for (int j=0; j<n; j++){
    scanf("%lf", &array[i][j]);
}}
double maximum = maxVal(n, array);
printf("Maximum value is %f", maximum);
return 0;
}
