#include<stdio.h>

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
}flight;

void departures (const char airportName[],
                 const char airportCity[],
                 const airport airportData[],
                 const flight flightSched[]){
    printf("Flight Departure - %s %s airport\n", airportCity, airportName);
    printf("Time    Flight             Destination\n");
    int x = -99;
    for(int i=0; i<4; i++){
        if(strcmp(airportData[i].name, airportName)==0){
            x=i;
            break;
        }
    }
    for(int j=0; j<99; j++){
        if(flightSched[j].from==x){
            printf("%02i:%02i    %s%i      %s-%s\n",
            flightSched[j].hour,
            flightSched[j].minute,
            flightSched[j].airline,
            flightSched[j].number,
            airportData[flightSched[j].to].city,
            airportData[flightSched[j].to].name);
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
    while (a<99){
        flightList[a].from=-99;
        a++;
    }
    int z=0;
    while (z<4){
        departures(airportList[z].name, airportList[z].city, airportList, flightList);
        z++;
    }
    fclose(file);
    fclose(infile);
    return 0;
}

