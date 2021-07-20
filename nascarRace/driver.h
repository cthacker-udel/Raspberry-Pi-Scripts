#include "baseinc.h"

typedef struct theDriver{

    char *name;
    int age;
    int racesWon;
    int racesLost;
    int racesTied;
    int cupsWon;

}driver;


char *getName();

int getAge();

int getRacesWon();

int getRacesLost();

int getRacesTied();

int getCupsWon();

void setName(char *);

void setAge(int);

void setRacesWon(int);

void setRacesLost(int);

void setRacesTied(int);

void setCupsWon(int);