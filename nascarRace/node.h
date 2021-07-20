#include "baseinc.h"
#include "driver.h"
#include "car.h"

typedef struct theNode{

    struct theNode *next;
    struct theNode *prev;
    car *theCar;
    driver *theDriver;

}node;