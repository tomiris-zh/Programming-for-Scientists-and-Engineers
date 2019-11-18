#include<stdio.h>

typedef struct {
    int customerID;
    char accounttype;
    double balance;
} BankCustomer;

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
int i=0;
int s=0, c=0, d=0;
double avgs=0, avgc=0, avgd=0;
BankCustomer cust[10];

FILE *file;
file=fopen("datafile.txt", "r");

if (file == NULL) {
    printf("Problem opening files.");
    return 1;
}

printf("File opened successfully");

do {
        fscanf(file, "%i %c %lf", &cust[i].customerID, &cust[i].accounttype, &cust[i].balance);
        printf("Customer ID: %i, type of account: %c and balance: %lf ", cust[i].customerID, cust[i].accounttype, cust[i].balance);
        i++;
} while(i<10);

for ( ; i<10; i++) {
    if(cust[i].accounttype == 's') {
            s++;
        avgs = avgs + cust[i].balance;
         printf("Average balance for savings is %.2lf\n", avgs/s);
    }
    else if(cust[i].accounttype == 'd') {
        d++;
        avgd = avgd + cust[i].balance;
         printf("Average balance for deposit is %.2lf\n", avgd/d);
    }
    else if (cust[i].accounttype == 'c') {
        c++;
        avgc = avgc + cust[i].balance;
         printf("Average balance for checking is %.2lf", avgc/c);
    }
    else {
        printf("Sorry");
    }
}
fclose(file);
return 0;
}

