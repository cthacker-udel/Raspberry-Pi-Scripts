#include "project.h"


car *HEAD = NULL;

void addCar(car *theCar){

    if(HEAD == NULL){
        HEAD = theCar;
    }
    else{
        theCar->next = HEAD;
        HEAD = theCar;
    }
    
}


