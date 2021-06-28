#include "DLL.hpp"

DLL::DLL(){

    HEAD = NULL;
    TAIL = NULL;

}

void DLL::addFirst(Node *newNode){

    HEAD = newNode;
    TAIL = newNode;

}

void DLL::addLast(Node *newNode){

    if(HEAD == NULL){
        HEAD = newNode;
        TAIL = newNode;
    }
    else{

        TAIL->next = newNode;
        TAIL = newNode;

    }

}