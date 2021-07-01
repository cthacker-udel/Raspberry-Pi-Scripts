#include "project.h"

node *HEAD = NULL;
node *TAIL = NULL;

int add(node *newNode){

    if(HEAD == NULL){

        HEAD = newNode;
        TAIL = newNode;

    }
    else{

        TAIL->next = newNode;
        newNode->previous = TAIL;
        TAIL = newNode;

    }

}