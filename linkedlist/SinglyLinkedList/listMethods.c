#include "project.h"

node *HEAD = NULL;

node *createNode(){

    int theVal;
    do{
        printf("\nPlease enter a value for the node\n");
    }while(scanf("%d",&theVal) != 1);

    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = theVal;
    newNode->next = NULL;
    return newNode;

}

void push(node *newNode){

    if(HEAD == NULL){
        HEAD = newNode;
    }
    else{

        node *tempHead = HEAD;
        while(tempHead->next != NULL){
            tempHead = tempHead->next;
        }
        tempHead->next = newNode;

    }


}

int pop(){

    if(HEAD == NULL){
        return NULL;
    }
    else{
        node *tempHead = HEAD;
        node *prevNode;
        while(tempHead->next != NULL){
            prevNode = tempHead;
            tempHead = tempHead->next;
        }
        prevNode->next = NULL;
        tempHead = NULL;
        return 1;
    }

}

int numNodes(){

    int count = 0;
    node *tempHead = HEAD;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;


}

void addHead(node *newNode){

    newNode->next = HEAD;
    HEAD = newNode;

}

void addTail(node *newNode){

    node *tempHead = HEAD;
    while(tempHead->next != NULL){
        tempHead = tempHead->next;
    }
    tempHead->next = newNode;

}


void insertNode(int index){

    if(index == 0){
        addHead(createNode());
    }
    else if(index >= numNodes()){
        addTail(createNode());
    }
    else{

        node *prevNode;
        node *tempHead = HEAD;
        int count = 0;
        while(tempHead->next != NULL){
            prevNode = tempHead;
            tempHead = tempHead->next;
            if(count == index){
                node *newNode = createNode();
                prevNode->next = newNode;
                newNode->next = tempHead;
                return;
            }
        }
        return;


    }



}