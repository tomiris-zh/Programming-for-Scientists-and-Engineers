#include <stdio.h>

typedef struct {
	int rain;
	double avgw, avgt;
} weather;

int main() {
	weather *w = (weather*)malloc(12+sizeof(weather));
	FILE*infile;
	infile = fopen("astana.txt","r");
	int i=0;
	int ra;
	double te, wi;
	do {
		fscanf(infile, "%i %lf %lf", &ra, &te, &wi);
		w[i].rain = ra;
		w[i].avgt = te;
		w[i].avgw = wi;
		i++;
	} while (!feof(infile));
	fclose(infile);
    return 0;
}
