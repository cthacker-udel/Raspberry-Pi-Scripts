#include "project.h"

node *ROOT = NULL;
node *TAIL = NULL;

void addNode(int value){
    
    node *theNode = createNodeV2(value);
    if(ROOT == NULL){
        ROOT = theNode;
        TAIL = theNode;
    }
    else{
    
        // insert
        node *tempHead = ROOT;
        while(tempHead->next != NULL){
            tempHead = tempHead->next;
        } 
        tempHead->next = theNode;
        theNode->prev = tempHead;
        TAIL = theNode;
    }


}


node *createNode(){

    int val = -1;

    do{
        printf("\nEnter a integer value for val");
    }while(scanf("%d",&val) == 0);

    node *newNode = malloc(sizeof(node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;


}

node *createNodeV2(int value){

    node *newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

}


void removeTail(){

    if(TAIL == NULL){

        // there is no tail
        printf("\nLIST IS EMPTY, UNABLE TO REMOVE TAIL\n");

    }
    else{

        if(TAIL->prev == NULL){
            // tail is only node
            TAIL = NULL;
            ROOT = NULL;
        }
        else{
            node *prevNode = TAIL->prev;
            prevNode->next = NULL;
            TAIL->prev = NULL;
            TAIL = NULL;
            TAIL = prevNode;
        }

    }

}

void removeHead(){

    if(ROOT == NULL){
        // list is already empty
        printf("\nUnable to remove head, list is already empty\n");
    }
    else{

        if(ROOT->next == NULL){
            ROOT = NULL;
            TAIL = NULL;
        }
        else{

            node *nextNode = ROOT->next;
            ROOT->next = NULL;
            ROOT = NULL;
            nextNode->prev = ROOT;

        }

    }


}

int nodeCount(){

    int count = 0;
    node *tempHead = ROOT;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;

}

int findLastIndex(int value){

    if(ROOT == NULL){
        // list is empty
        return -1;
    }
    else if(ROOT->next == NULL){

        if(ROOT->val == value){
            return 0;
        }
        else{
            return -1;
        }

    }
    else{

        node *tempTail = TAIL;
        int ind = nodeCount()-1;
        while(tempTail != NULL){
            if(tempTail->val == value){
                return ind;
            }
            tempTail = tempTail->prev;
            ind--;
        }
        return -1;
    }

}

int findFirstIndex(int value){

    if(ROOT == NULL){
        // list is empty
        return -1;
    }
    else if(ROOT->next == NULL){

        if(ROOT->val == value){
            return 0;
        }
        else{
            return -1;
        }

    }
    else{

        int ind = 0;
        node *tempHead = ROOT;
        while(tempHead != NULL){
            if(tempHead->val == value){
                return ind;
            }
            tempHead = tempHead->next;
            ind++;
        }
        return -1;


    }


}

