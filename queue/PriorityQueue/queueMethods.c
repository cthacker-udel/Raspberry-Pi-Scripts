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

int contains(node *theNode){

    node *tempHead = HEAD;
    while(tempHead != NULL){

        if(tempHead == theNode){

            return 1;

        }
        tempHead = tempHead->next;

    }
    return 0;

}

int offer(node *theNode){

    if(size() == max_size){

        printf("\n-=-=-=SIZE ERROR-=-=-=\nYou are trying to add a node to a list that has reached max size, increase the max size\n-=-=-=-=-=-=-=-=-=-=");
        return 0;

    }
    else{

        TAIL->next = theNode;
        theNode->previous = TAIL;
        TAIL = theNode;

    }

}


node *peek(){

    return TAIL;

}

node *poll(){

    if(size() == 1){

        free(HEAD);
        free(TAIL);

    }
    else{

        node *prevNode = TAIL->previous;
        prevNode->next = NULL;
        free(TAIL);
        TAIL = prevNode;

    }

}

int remove(node *theNode){

    if(!contains(theNode)){
        printf("\nThe linked list does not contain the node you are trying to remove\n");
        return 0;
    }

}

int size(){

    node *tempHead = HEAD;
    int count = 0;
    while(tempHead != NULL){
        tempHead = tempHead->next;
        count++;
    }
    return count;

}