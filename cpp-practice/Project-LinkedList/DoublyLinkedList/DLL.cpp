#include "DLL.hpp"

DLL::DLL(){

    HEAD = NULL;
    TAIL = NULL;

}

void DLL::addFirst(Node *newNode){

    HEAD = newNode;
    TAIL = newNode;

}