#include "project.h"


car *HEAD = NULL;


car *createCar(int weight, char *name){

    car *newCar = (car *)malloc(sizeof(car));
    newCar->weight = weight;
    strcpy(newCar->name,name);
    return newCar;

}

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

void insertCar(car *theCar, int index){

    car *tempHead = HEAD;
    int count = 0;
    int numOfCars = numCars();
    if(numOfCars == 0){
        addCar(theCar);
        return;
    }
    else{

        if(index >= numOfCars){
            addTail(theCar);
            return;
        }
        else if(index <= 0){
            addHead(theCar);
        }
        else{

            car *prevNode;
            while(tempHead != NULL){
                count++;
                prevNode = tempHead;
                tempHead = tempHead->next;
                if(count == index){
                    prevNode->next = tempHead->next;
                    tempHead->next = NULL;
                    tempHead = NULL;
                    return;
                }
            }
            return;

        }

    }

}

void reverseTrain(){

    int numOfCars = numCars();
    if(numOfCars == 1){
        return;
    }
    else{
        car *prevNode = HEAD;
        car *currNode = HEAD->next;
        car *forwardNode;
        prevNode->next = NULL;
        while(forwardNode != NULL){
            forwardNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = forwardNode;
        }
    }

}


car * findCar(int index){

    int numOfCars = numCars();
    if(numOfCars > 0){
        if(index <= 0){
            return HEAD;
        }
        else if(index >= numOfCars){
            car *tempHead = HEAD;
            while(tempHead->next != NULL){
                tempHead = tempHead->next;
            }
            return tempHead;
        }
        else{

            int count = 0;
            car *tempHead = HEAD;
            while(tempHead != NULL){
                count++;
                tempHead = tempHead->next;
                if(count == index){
                    return tempHead;
                }
            }

        }
    }
    else{
        return NULL;
    }

}


void sortCars(){

    car *tempHead = HEAD;

    int numOfCars = numCars();

    if(numOfCars > 1){
        int loopVar = 1;
        while(1){

            car *prevNode = HEAD;
            car *forwardNode;
            while(forwardNode != NULL){
                forwardNode = prevNode->next;
                if(prevNode->weight > forwardNode->weight){
                    prevNode->next = forwardNode->next;
                    forwardNode->next = prevNode;
                    if(prevNode == HEAD){
                        HEAD = forwardNode;
                        loopVar = 0;
                    }
                    break;
                }
                loopVar = 1;
            }
            if(loopVar){
                break;
            }
        }
    }
}

void addHead(car *theCar){
    theCar->next = HEAD;
    HEAD = theCar;
}

void addTail(car *theCar){
    car *tempHead = HEAD;
    while(tempHead->next != NULL){
        tempHead = tempHead->next;
    }
    tempHead->next = theCar;
}

void removeHead(){

    int NumOfCars = numCars();

    if(NumOfCars < 2){
        HEAD = NULL;
    }
    else{
        car *nextCar = HEAD->next;
        HEAD->next = NULL;
        HEAD = NULL;
        HEAD = nextCar;
    }
}

void removeTail(){

    int NumOfCars = numCars();

    if(NumOfCars < 2){
        HEAD = NULL;
    }
    else{

        car *tempHead = HEAD->next;
        car *prevNode;
        while(tempHead->next != NULL){
            prevNode = tempHead;
            tempHead = tempHead->next;
        }
        prevNode->next = NULL;
        tempHead = NULL;
    }

}

void displayTrain(){
    car *tempHead = HEAD;
    int count = 1;
    while(tempHead != NULL){
        if(count == 1){
            printf("\nHEAD OF TRAIN : Weight[%d] Name[%s]\n",tempHead->weight,tempHead->name);
            count++;
        }
        else{
            printf("\nTRAIN CAR %d : Weight[%d] Name[%s]\n",count++,tempHead->weight,tempHead->name);
        }
    }
}


