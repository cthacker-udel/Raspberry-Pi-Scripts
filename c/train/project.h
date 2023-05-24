#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

typedef struct trainCar{

    int weight;
    char *name;
    struct trainCar *next;

}car;


void printMenu();

car *createCar(int,char *);

void addCar(car *);

void deleteCar(int,char *);

void reverseTrain();

void insertCar(car *, int);

car * findCar(int);

void sortCars();

void addHead(car *);

void addTail(car *);

void removeHead();

void removeTail();

int numCars();

void displayTrain();
