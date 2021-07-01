#include "project.h"

node *HEAD = NULL;
node *TAIL = NULL;

int add(node *newNode){

    if(HEAD == NULL){

        HEAD = newNode;
        TAIL = newNode;
        return 1;
    }
    else if(size() == max_size){

        printf("\n-=-=-=ERROR : MAX SIZE-=-=-=\nLinked List is at max size, cannot add nodes\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        return 0;

    }
    else{

        TAIL->next = newNode;
        newNode->previous = TAIL;
        TAIL = newNode;
        return 1;
    }

}

void increaseSize(int addSize){

    max_size += addSize;

}

void clear(){

    node *currNode = HEAD;
    node *prevNode;
    while(currNode != NULL){
        prevNode = currNode;
        currNode = currNode->next;
        free(prevNode);
    }
}