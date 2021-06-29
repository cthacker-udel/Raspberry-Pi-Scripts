#include "project.h"

node *HEAD = NULL;
node *TAIL = NULL;

int MAX_SIZE = 0;

int add(node *newNode){

    if(size()  == MAX_SIZE){

        printf("\n-=-=-=ERROR : MAX SIZE : UNABLE TO ADD ELEMENT : INCREASE SIZE -=-=-=\n");
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
            TAIL = newNode;
        }

    }

}

int increaseSize(int amount){
    MAX_SIZE += amount;
    return 1;
}

node *element(){
    
    node *tempHead = HEAD;
    while(tempHead->next != NULL){
        tempHead = tempHead->next;
    }
    return tempHead;

}
