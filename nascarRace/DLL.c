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

void moveDown(int id){

    if(theList->first == NULL){
        printf("\nList is empty, must have nodes to move nodes down\n");
    }
    else if(theList->first->next == NULL){
        printf("\nList only has one node\n");
    }
    else{

        if(theList->first->id == id){
            // first contains id
            printf("\nFirst node is the node to move down\n");
        }
        else if(theList->last->id == id){
            // last contains id
            printf("\nLast node is the node to move down\n");
        }
        else{

            node *tempLast = theList->last;
            while(tempLast != NULL){

                if(tempLast->id == id){
                    // located node
                    node *prevTemp = tempLast->prev;
                    node *prevForward = tempLast->next;
                    // grab both nodes behind and in front
                    printf("\nLocated node in the middle of list\n");



                }
                tempLast = tempLast->prev;
            }

        }

    }


}


void raceOff(int racer1id, int racer2id){

    node *racer1Node = NULL;
    node *racer2Node = NULL;

    node *tempLast = theList->last;
    while(tempLast != NULL){
        if(tempLast->id == racer1id){
            racer1Node = tempLast;
            break;
        }
        tempLast = tempLast->prev;
    }

    tempLast = theList->last;
    while(tempLast != NULL){
        if(tempLast->id == racer2id){
            racer2Node = tempLast;
            break;
        }
        tempLast = tempLast->prev;
    }

    if(racer1Node == NULL && racer2Node == NULL){
        printf("\nBoth racer1 and racer2 have not been found, no results have been announced\n");
        return;
    }
    else if(racer1Node == NULL){
        // racer1 has not been found
        printf("\nRacer one has not been found, automatic victory for racer2!");
        racer2Node->driver->racesWon++;
        printf("\nMoving up racer2 in the list(rankings), and adding a victory to their score sheet\n");
        moveUp(racer2Node->id);
    }
    else if(racer2Node == NULL){
        printf("\nRacer2 has not been found, automatic victory for racer1!\nMoving up racer1 in the list(rankings) and also adding a victory to their score sheet\n");
        racer1Node->driver->racesWon++;
        moveUp(racer1Node->id);
    }
    else{

        // even number racer1 wins, odd number racer2 wins
        int randNumber = rand() * rand() * pow(rand(),2);
        if(randNumber % 2 == 0){
            // racer1 wins!
            printf("\nRacer1 has won! Moving up racer1 in the list(rankings) and also moving racer2 down, wins and losses have been accredited\n");
            racer1Node->driver->racesWon++;
            racer2Node->driver->racesLost++;
            moveUp(racer1Node);
            moveDown(racer2Node);
        }
        else{
            // racer2 wins!
            printf("\nRacer2 has won! Moving up racer2 in the list(rankings) and also moving down racer1, wins and losses have been accredited\n");
            racer2Node->driver->racesWon++;
            racer1Node->driver->racesLost++;
            moveUp(racer2Node->id);
            moveDown(racer1Node->id);
        }

    }

}

void printMenu(){

    print("\n-=-=-=-=MENU-=-=-=-=\n1)Push node\n2)Pop Node\n3)Dequeue Node\n4)Remove node by ID\n5)Move Up Node by ID");

}