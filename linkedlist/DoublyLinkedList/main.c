#include "project.h"

node *ROOT = NULL;
node *TAIL = NULL;

void addNode(int value){

    if(ROOT == NULL){
        node *theNode = createNodeV2(value);
        ROOT = theNode;
        TAIL = theNode;
    }
    else{
    
        // insert 
    
    }


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

node *createNodeV2(int value){

    node *newNode = malloc(sizeof(node));
    newNode->value = value;

    return newNode;

}

