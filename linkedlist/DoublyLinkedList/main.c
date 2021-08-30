#include "project.h"

node *ROOT = NULL;

void addNode(int value){

    


}


node *createNode(){

    int val = -1;

    do{
        printf("\nEnter a integer value for val");
    }while(scanf("%d",&val) == 0);

    node *newNode = malloc(sizeof(node));
    newNode->value = val;
    return newNode;


}




