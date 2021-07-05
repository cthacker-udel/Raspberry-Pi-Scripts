#include "project.h"

node *HEAD = NULL;

node *createNode(){

    int theVal;
    do{
        printf("\nPlease enter a value for the node\n");
    }while(scanf("%d",&theVal) != 1);

    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = theVal;
    return newNode;

}