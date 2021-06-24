#include "project.h"

node *HEAD = NULL;

node *createNode(int newValue){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = newValue;
    newNode->next = NULL;
    return newNode;
}

int push(int newValue){
    if(HEAD == NULL){
        // 1 line
    }
    else{
        // 2 lines
    }
}


