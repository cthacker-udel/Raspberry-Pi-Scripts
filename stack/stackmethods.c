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
        HEAD = createNode(newValue);
    }
    else{
        node *newNode = createNode(newValue);
        newNode->next = HEAD;
        HEAD = newNode;
    }
}


