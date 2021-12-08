#include "baseinc.h"
#include "driver.h"
#include "car.h"

typedef struct theNode{

    struct theNode *next;
    struct theNode *prev;
    int id;
    car *theCar;
    driver *driver;

}node;