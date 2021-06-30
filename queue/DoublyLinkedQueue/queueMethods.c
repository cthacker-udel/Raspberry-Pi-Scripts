#include "project.h"




int add(node *newNode){

    if(size() == MAX_SIZE){
        printf("\n-=-=-=SIZE ERROR-=-=-=\nINCREASE SIZE BEFORE ADDING NODES\n-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return 0;
    }
    else{
        if(HEAD == NULL){
            HEAD = newNode;
            TAIL = newNode;
        }
        else{

            node *tempHead = HEAD;
            while(tempHead->next != NULL){
                tempHead = tempHead->next;
            }
            tempHead->next = newNode;
            TAIL = newNode
        }
    }

}