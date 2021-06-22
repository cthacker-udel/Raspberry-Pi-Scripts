#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

typedef struct trainCar{

    int weight;
    char *name;
    struct trainCar *next;

}car;


void addCar(car *);

void deleteCar(car *);

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