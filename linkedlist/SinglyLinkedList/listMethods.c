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