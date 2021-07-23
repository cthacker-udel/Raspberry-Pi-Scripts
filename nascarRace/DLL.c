#include "DLL.h"

DLL *theList = NULL;

void printMenu(){

    printf("\n-=-=-=MENU-=-=-=\n1)Push Node\n2)Pop from list\n3)Move Up Node\n4)Move Down Node\n5)Race off two nodes\n6)Exit program");

}


void push(node *newNode){

    if(theList->first == NULL || theList->last == NULL){
        theList->first = newNode;
        theList->last  = newNode;
    }
    else if(theList->first == theList->last){

        theList->last->next = newNode;
        newNode->prev = theList->last;
        theList->last = newNode;

    }
    else{

        node *tempLast = theList->last;
        while(tempLast != NULL && tempLast->driver->ranking > newNode->driver->ranking){
            tempLast = tempLast->prev;
        }

        if(tempLast == NULL){
            newNode->next = theList->first;
            theList->first->prev = newNode;
            theList->first = newNode;
        }
        else if(tempLast == theList->first){

            theList->first->next->prev = newNode;
            newNode->next = theList->first->next;
            newNode->prev = theList->first;

        }



    }


}

node *createNode(){

    node *newNode = malloc(sizeof(node));

    char *carModel = malloc(sizeof(char) * 100);

    do{
        printf("Enter the name of the car model\n");
    }while(!scanf("%s",carModel));

    int manufacturerYear;

    do{
        printf("Enter the manufacturer year\n");
    }while(!scanf("%d",&manufacturerYear));

    int miles;

    do{
        printf("\nEnter the miles on the car");
    }while(!scanf("%d",&miles));

    newNode->theCar = malloc(sizeof(car));

    newNode->theCar->manufacturerYear = manufacturerYear;
    newNode->theCar->model = carModel;
    newNode->theCar->miles = miles;

    newNode->driver = malloc(sizeof(driver));

    char *name = malloc(sizeof(char) * 100);

    do{
        printf("\nEnter the name of the driver");
    }while(!scanf("%s",name));
    
    int age;
    int racesWon;
    int racesLost;
    int racesTied;
    int cupsWon;
    int ranking;

    do{
        printf("\nEnter the age of the driver");
    }while(!scanf("%d",&age));


    do{
        printf("\nEnter the amount of races won");
    }while(!scanf("%d",&racesWon));

    do{
        printf("\nEnter the amount of races lost");
    }while(!scanf("%d",&racesLost));

    do{
        printf("\nEnter the amount of races tied");
    }while(!scanf("%d",&racesTied));

    do{
        printf("\nEnter the amount of cups won");
    }while(!scanf("%d",&cupsWon));

    do{
        printf("\nEnter the ranking of the driver(1-10)");
    }while(!scanf("%d",&cupsWon));

    newNode->driver->age = age;
    newNode->driver->name = name;
    newNode->driver->racesLost = racesLost;
    newNode->driver->racesWon = racesWon;
    newNode->driver->racesTied = racesTied;
    newNode->driver->cupsWon = cupsWon;
    newNode->driver->ranking = ranking;

    return newNode;


}

node *pop(){

    if(theList->last == NULL){
        printf("\nAttempting to pop a node from the end of the list\n");
        return NULL;
    }
    else if(theList->first->next == NULL){
        printf("\nOnly one node in list, deleting entire list\n");
        node *tempNode = theList->first;
        free(theList->first);
        free(theList->last);
        return tempNode;
    }
    else{

        theList->last->prev = theList->last;
        node *lastNode = theList->last->next;
        theList->last->next->prev = NULL;
        theList->last->next = NULL;
        return lastNode;

    }


}

node *dequeue(){

    if(theList->first == NULL){
        printf("\nAttempting to dequeue a list that is empty\n");
        return NULL;
    }
    else if(theList->first->next == NULL){
        printf("\nAttempting to dequeue list with only one node, deleting list\n");
        node *tempNode = theList->first;
        free(theList->first);
        free(theList->last);
        return tempNode;
    }
    else{

        node *nextFirst = theList->first->next;
        theList->first->next = NULL;
        nextFirst->prev = NULL;
        node *tempNode = theList->first;
        theList->first = nextFirst;
        return tempNode;

    }

}

int remove(int idNum){

    if(theList->last == NULL || theList->first == NULL){
        printf("\nAttempting to remove a node when the list is empty\n");
        return 0;
    }
    else{

        if(theList->last->id == idNum){
            pop();
            return 1;
        }
        if(theList->first->id == idNum){
            dequeue();
            return 1;
        }
        node *tempLast = theList->last;
        while(tempLast != NULL){
            if(tempLast->id == idNum){
                
                tempLast->prev->next = tempLast->next;
                tempLast->next->prev = tempLast->prev;
                tempLast->prev = NULL;
                tempLast->next = NULL;
                tempLast = NULL;
                return 1;
                

            }
            tempLast = tempLast->prev;
        }
        return 0;
    }


}

void moveUp(int id){


    if(theList->first == NULL){

        printf("\nThe list has no nodes available, create nodes to move nodes up\n");
        return;

    }
    else if(theList->first->next == NULL){

        // list only has one node

        printf("\nList only has one node, must have two nodes to move a node up\n");
        return;


    }
    else if(theList->first->id == id){

        // first has id

    }
    else if(theList->last->id == id){

        // last has id

    }
    else{

        node *lastNode = theList->last;
        while(lastNode != NULL){

            if(lastNode->id == id){

                node *prevPrev = lastNode->prev->prev;
                prevPrev->next = lastNode;
                // check prevprev
                
                lastNode->prev->next = lastNode->next;
                lastNode->prev->prev = lastNode;
                
                // check prev node
                
                lastNode->next->prev = lastNode->prev;
                
                // check next node

                lastNode->next = lastNode->prev;
                lastNode->prev = prevPrev;

                // check curr node

                if(lastNode->next->driver->ranking < lastNode->driver->ranking){
                    lastNode->driver->ranking = lastNode->next->driver->ranking;
                }

                printf("\nNode moved!\n");
                return;


            }
            lastNode = lastNode->prev;


        }
        printf("\nNode unable to be found, make sure id is correct\n");
        return;

    }

}

void printMenu(){

    print("\n-=-=-=-=MENU-=-=-=-=\n1)Push node\n2)Pop Node\n3)Dequeue Node\n4)Remove node by ID\n5)Move Up Node by ID");

}