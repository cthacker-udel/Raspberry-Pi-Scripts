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

int numCars(){

    car *tempHead = HEAD;
    int count = 0;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;

}

void deleteCar(car *theCar){

    int theNumCars = numCars();
    if(theNumCars == 0){
        return;
    }
    else if(theNumCars == 1){
        removeHead();
    }
    else{

        car *tempCar = HEAD;
        car *prevNode;
        while(tempCar->next != NULL){
            prevNode = tempCar;
            if(tempCar == theCar){
                prevNode->next = tempCar->next;
                tempCar->next = NULL;
                tempCar = NULL;
                return;
            }
            tempCar = tempCar->next;
        }
        return;    
    }
}


