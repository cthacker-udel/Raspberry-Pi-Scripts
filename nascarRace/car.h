#include "baseinc.h"

typedef struct theCar{

    char *model;
    int manufacturerYear;
    int miles;

}car;

void setModel(char *);

void setManufacturerYear(int);

void setMiles(int);

char *getModel();

int getManufacturerYear();

int getMile();
