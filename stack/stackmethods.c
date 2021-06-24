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

void displayStack(){
    node *tempHead = HEAD;
    int count = 1;
    printf("\n\n~-~-~-~-DISPLAYING STACK~-~-~-~-\n\n");
    while(tempHead != NULL){
        printf("\n------\nNODE %d : %d\n------\n",count++,tempHead->value);
        tempHead = tempHead->next;
    }
}

int size(void){
    int count = 0;
    node *tempHead = HEAD;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;
}


