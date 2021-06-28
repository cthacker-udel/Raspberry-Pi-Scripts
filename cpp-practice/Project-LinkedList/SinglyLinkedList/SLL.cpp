#include "SLL.hpp"
#include <stdlib.h>
using namespace std;


SLL::SLL(){

    first = NULL;
    last = NULL;

}

SLL::SLL(Node *newNode){

    first = newNode;
    last = newNode;

}

void SLL::push(Node *newNode){

    if(this->first == NULL){
        addFirst(newNode);
    }
    else{
        last->next = newNode;
        last = newNode;
    }
}

Node *SLL::pop(){

    if(this->first == NULL){
        return NULL;
    }
    else if(this->first->next == NULL){
        Node *tempHead = first;
        this->first = NULL;
        return tempHead;
    }
    else{
        Node *tempNode = first;
        Node *prevNode;
        while(tempNode->next != NULL){
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
        prevNode->next = NULL;
        delete tempNode;
    }

}

