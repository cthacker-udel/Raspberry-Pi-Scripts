#include "project.h"
#include <string.h>

car *HEAD = NULL;


car *createCar(int weight, char *name){

    car *newCar = (car *)malloc(sizeof(car));
    printf("\nString = %s",name);
    newCar->weight = weight;
    newCar->name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(newCar->name,name);
    return newCar;

}

void printMenu(){

    printf("\n-~-~-~-~-MENU-~-~-~-~\n-~-~-~-~-~-~-~-~-~-~-~\n1 : Add Car\n2 : Delete Car\n3 : Reverse Train\n4 : Find Car\n5 : Sort Cars(Ascending)\n6 : Add Head\n7 : Add Tail\n8 : Remove Head\n9 : Remove Tail\n10 : Display Train\n11 : Exit Program\n-~-~-~-~-~-~-~-~-\n");

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

void deleteCar(int weight, char *name){

    int theNumCars = numCars();
    if(theNumCars == 0){
        return;
    }
    else if(theNumCars == 1){
        if(HEAD->weight == weight && strcmp(HEAD->name,name) == 0){
            removeHead();
            return;
        }
        else{
            return;
        }
    }
    else if(HEAD->weight == weight && strcmp(HEAD->name,name) == 0){
        car *tempCar = HEAD->next;
        HEAD->next = NULL;
        HEAD = NULL;
        HEAD = tempCar;
    }
    else{
        car *tempCar = HEAD;
        car *prevNode;
        while(tempCar != NULL){
            prevNode = tempCar;
            tempCar = tempCar->next;
            if(tempCar->weight == weight && strcmp(tempCar->name,name) == 0){
                printf("\n\nReached inner if in while loop\n\n");
                prevNode->next = tempCar->next;
                tempCar->next = NULL;
                tempCar = NULL;
                return;
            }
        }
        printf("\n\nReached last return in deleteCar\n\n");
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
    else if(numOfCars == 2){
        car *newCard = HEAD->next;
        newCard->next = HEAD;
        HEAD->next = NULL;
        HEAD = newCard;
    }
    else{
        car *prevNode = HEAD;
        car *currNode = HEAD->next;
        car *forwardNode;
        prevNode->next = NULL;
        while(forwardNode != NULL){
            printf("Entering while\n");
            forwardNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = forwardNode;
        }
        HEAD = prevNode;
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


    int numOfCars = numCars();

    if(numOfCars > 1){
        int loopVar = 1;
        while(1){
            car *tempHead = HEAD;
            //displayTrain();
            //sleep(3);
            car *prevNode = HEAD;
            car *forwardNode;
            while(prevNode != NULL && forwardNode != NULL){
                forwardNode = prevNode->next;
                if(forwardNode != NULL && prevNode->weight > forwardNode->weight){
                    prevNode->next = forwardNode->next;
                    forwardNode->next = prevNode;
                    if(prevNode == HEAD){
                        HEAD = forwardNode;
                        loopVar = 0;
                    }
                    else{
                        HEAD = tempHead;
                        car *temp = HEAD;
                        while(temp->next != NULL){
                            if(temp->next == prevNode){
                                temp->next = forwardNode;
                                break;
                            }
                        }
                        loopVar = 0; 
                    }
                    break;
                }
                loopVar = 1;
                prevNode = prevNode->next;
            }
            if(loopVar){
                HEAD = tempHead;
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
        }
        else{
            printf("\nTRAIN CAR %d : Weight[%d] Name[%s]\n",count,tempHead->weight,tempHead->name);
        }
        count++;
        tempHead = tempHead->next;
    }
}


