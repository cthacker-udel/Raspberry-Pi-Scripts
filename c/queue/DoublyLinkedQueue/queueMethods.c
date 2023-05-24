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
            newNode->previous = TAIL;
            TAIL = newNode;
        }
    }

}

node *craftNode(){

    int value;
    printf("\n-=-=-=USER INPUT-=-=-=\nEnter a value to assign to new node : ");
    scanf("%d",&value);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;
    return newNode;

}

node *element(){

    return TAIL;

}

int offer(node *newNode){

    if(size() == MAX_SIZE){
        printf("\n-=-=-=SIZE ERROR-=-=-=\nAttempting to insert node when list has reached max size, please increase the size\n-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return 0;
    }
    else{
        TAIL->next = newNode;
        newNode->previous = TAIL;
        TAIL = newNode;
    }

}

node *peek(){

    return TAIL;

}

node *poll(){

    if(TAIL == NULL){
        printf("\n-=-=-=ERROR : TAIL IS NULL-=-=-=\nThe Doubly Linked Queue you are attempting to poll from is currently empty, please add a node to the list to poll from it\n-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return NULL;
    }
    else{
        node *newTail = TAIL->previous;
        newTail->next = NULL;
        TAIL = NULL;
        TAIL = newTail;
    }

}

node *removeHead(){

    if(TAIL == NULL){
        printf("\n-=-=-=ERROR : TAIL IS NULL-=-=-=\nThe Doubly Linked Queue you are trying to remove the head from is empty, please add a node to the list to remove a node\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return NULL;
    }
    else{

        node *newTail = TAIL->previous;
        newTail->next = NULL;
        TAIL = NULL;
        TAIL = newTail;

    }

}

int increaseSize(int newSize){

    MAX_SIZE += newSize;
    return 1;

}


int contains(node *newNode){

    if(TAIL == NULL){

        printf("\n-=-=-=CONTAINS ERROR-=-=-=\nThe Doubly Linked Queue you are trying to test if it contains a node is currently empty, please add a node to test if it contains a node\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return 0;

    }
    else{

        node *tempHead = HEAD;
        while(tempHead != NULL){
            if(tempHead == newNode){
                return 1;
            }
            tempHead = tempHead->next;
        }
        return 0;

    }

}

int isEmpty(){

    return (TAIL == NULL || HEAD == NULL)? 1: 0;

}

int removeAll(){

    if(HEAD == NULL){
        printf("\n-=-=-=-=REMOVEALL ERROR-=-=-=-=\nThe Doubly Linked Queue you are currently trying to remove all nodes from is currently empty, try adding nodes before removing all of them\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return 0;
    }
    else{

        node *tempHead = HEAD;
        node *prevNode;
        while(tempHead != NULL){
            prevNode = tempHead;
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
        printf("\n-=-=-=CLEAR ERROR-=-=-=\nThe Doubly Linked Queue you are trying to clear is currently empty\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return 0;
    }
    else{

        node *tempHead = HEAD;
        node *prevNode;
        while(tempHead != NULL){
            prevNode = tempHead;
            tempHead = tempHead->next;
            free(prevNode);
        }

    }

}

int *toArray(){

    int *arr = (int *)malloc(sizeof(int) * size());
    node *tempHead = HEAD;
    for(int i = 0; tempHead != NULL; i++, tempHead = tempHead->next){
        *(arr+i) = tempHead->value;
    }
    return arr;

}

