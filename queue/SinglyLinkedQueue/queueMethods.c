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
    
    return TAIL;

}

int offer(node *newNode){

    if(size() == MAX_SIZE){
        printf("\n-=-=-=ERROR : MAX SIZE : UNABLE TO ADD ELEMENT : INCREASE SIZE -=-=-=\n");
        return 0;
    }
    else{
        node *tempHead = HEAD;
        while(tempHead->next != NULL){
            tempHead = tempHead->next;
        }
        tempHead->next = newNode;
        TAIL = newNode;
        return 1;
    }

}

node *peek(){
    return TAIL;
}

node *poll(){
    if(HEAD == NULL){
        return NULL;
    }
    else{
        node *tempHead = HEAD;
        while(tempHead->next != TAIL){
            tempHead = tempHead->next;
        }
        node *theNode = (node *)malloc(sizeof(node));
        *theNode = *TAIL;
        tempHead->next = NULL;
        TAIL = NULL;
        TAIL = tempHead;
        return theNode;
    }
}

node *removeHead(){
    if(HEAD == NULL){
        return NULL;
    }
    else{
        node *tempHead = HEAD;
        while(tempHead->next != TAIL){
            tempHead = tempHead->next;
        }
        node *returnNode = (node *)malloc(sizeof(node));
        tempHead->next = NULL;
        *returnNode = *TAIL;
        TAIL = NULL;
        TAIL = tempHead;
        return returnNode; 
    }
}

int contains(node *theNode){
    if(HEAD == NULL){
        return 0;
    }
    else{
        node *tempHead = HEAD;
        while(tempHead != NULL){
            if(tempHead == theNode){
                return 1;
            }
            else{
                tempHead = tempHead->next;
            }
        }
        return 0;
    }
}

int isEmpty(){
    return size() == 0? 1: 0;
}

int removeAll(){
    if(HEAD == NULL){
        printf("\n-=-=-=ERROR : ATTEMPTING TO REMOVE AN ALREADY EMPTY LIST-=-=-=\n");
        return 0;
    }
    else{
        node *tempHead = HEAD;
        while(tempHead != NULL){
            node *prevNode = tempHead;
            tempHead = tempHead->next;
            free(prevNode);
        }
        return 1;
    }
}

int size(){
    int count = 0;
    node *tempHead = HEAD;
    while(tempHead != NULL){
        tempHead = tempHead->next;
        count++;
    }
    return count;
}

int clear(){
    if(HEAD == NULL){
        printf("\n-=-=-=ERROR : ATTEMPTING TO CLEAR AN ALREADY EMPTY LIST-=-=-=\n");
        return 0;
    }
    else{
        node *tempHead = HEAD;
        while(tempHead != NULL){
            node *prevNode = tempHead;
            tempHead = tempHead->next;
            free(prevNode);
        }
        return 1;
    }
}
