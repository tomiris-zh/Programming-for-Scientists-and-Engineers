#include<stdio.h>
#include <string.h>

typedef struct{
   char name[99];
   char city[99];
   int timeZone;
   int numberOfTerminals;
   char terminals[99];
}airport;

typedef struct{
    char airline[99];
    int number;
    int from;
    int to;
    int hour;
    int minute;
    int duration;
    int currentDelay;
    char depTerminal;
    int depGate;
}flight;

void departures (int hh, int mm,
			 	 const char airportName[],
                 const char airportCity[],
                 const airport airportData[],
                 const flight flightSched[]){
    if(mm > 59 || mm < 0 || hh > 23 || hh < 0) {
    	printf("Incorrect Time");
    }
    int i;
    for(i = 0; i < 4 && strcmp(airportCity, airportData[i].city); i++) {}
    int output_time = hh + airportData[i].timeZone;
    printf("Flight Departure - %s %s airport - Local Time: %02d:%02d\n", airportCity, airportName, output_time, mm);
    printf("Time    Flight             Destination\t Ter  Gate  Delay\n");
    int x = -99;
    for(i=0; i<4; i++){
        if(strcmp(airportData[i].name, airportName)==0){
            x=i;
            break;
        }
    }
    for(int j=0; j<99; j++){
        if(flightSched[j].from==x && output_time<=flightSched[j].hour){
            printf("%02i:%02i    %s%i\t   %s-%s\t  ",
            flightSched[j].hour,
            flightSched[j].minute,
            flightSched[j].airline,
            flightSched[j].number,
            airportData[flightSched[j].to].city,
            airportData[flightSched[j].to].name);

	    printf("%c\t", flightSched[j].depTerminal);
	    if(flightSched[j].depGate > 0) {
	    	printf("%d   ", flightSched[j].depGate);
	    }
		else {
			printf("    ");
		}
	    if(flightSched[j].currentDelay > 0){
	    	printf("%dm\n", flightSched[j].currentDelay);
	    }
		else {
			printf("\n");
		}
        }
    }
    printf("\n");
}


int main(){
    airport airportList[4];
    flight flightList[99];
    FILE *file;
    FILE *infile;
    file=fopen("airports.txt","r");
    infile=fopen("schedule.txt","r");
    if (infile==NULL || file==NULL){
        printf("Problem opening file");
        return 1;
}
    int a=0, b=0;
    do{
        fscanf(file, " %s %i %s ", airportList[a].city, &airportList[a].timeZone, airportList[a].name);
        while(!feof(file)){
            airportList[a].terminals[b]=fgetc(file);
            if (airportList[a].terminals[b]==EOF){
                break;
            }
            if(airportList[a].terminals[b]=='\n'){
                break;
            }
            if(airportList[a].terminals[b]==' '){
                continue;
            }
            b++;
        }
        airportList[a].numberOfTerminals = 0;
        a++;
    } while(!feof(file));
    for(a = 0; a < 99; a++) {
    flightList[a].depTerminal = ' ';
	flightList[a].depGate = 0;
	flightList[a].currentDelay = 0;
   }
    a=0;
    do{
        char from[99];
        char fromAirport[99];
        char to[99];
        char toAirport[99];
        fscanf(infile, "%s %i %s %s - %s %s %i %i ", flightList[a].airline, &flightList[a].number, fromAirport, from, toAirport, to, &flightList[a].hour, &flightList[a].duration);
        flightList[a].minute = flightList[a].hour%100;
        flightList[a].hour/=100;
        flightList[a].from=-99;
        flightList[a].to=-99;
        int x=0, y=0;
        while (x<4){
            if (strcmp(airportList[x].name, from)==0){
                flightList[a].from=x;
                break;
            }
            x++;
        }
        while (y<4){
            if (strcmp(airportList[y].name, to)==0){
                flightList[a].to=y;
                break;
            }
            y++;
        }
        a++;
    }while(!feof(infile));
	fclose(file);
    fclose(infile);
    while (a<99){
        flightList[a].from=-99;
        a++;
    }
    file=fopen("rtGates.txt","r");
    infile=fopen("rtFlights.txt","r");
     do{
        char from[99];
        char depTerminal;
	int number, depGate;
        fscanf(file, "%s %i %c %i", from, &number, &depTerminal, &depGate);
        int x=0;
        while (x<99){
            if (strcmp(flightList[x].airline, from)==0 && flightList[x].number == number){
                flightList[x].depTerminal=depTerminal;
	        flightList[x].depGate=depGate;
                break;
            }
            x++;
        }
    }while(!feof(file));
     do{
        char from[99];
        int number, depTime;
        fscanf(infile, "%s %i %i", from, &number, &depTime);
        int x=0;
        while (x<99){
            if (strcmp(flightList[x].airline, from)==0 && flightList[x].number == number){
                flightList[x].currentDelay=depTime;

                break;
            }
            x++;
        }
    }while(!feof(infile));

    int z=0;
    while (z<4){
        departures(1, 0, airportList[z].name, airportList[z].city, airportList, flightList);
        z++;
    }
    return 0;
}

