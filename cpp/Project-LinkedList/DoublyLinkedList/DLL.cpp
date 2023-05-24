#include "DLL.hpp"

DLL::DLL(){

    HEAD = NULL;
    TAIL = NULL;

}

void DLL::push(Node *newNode){

    if(TAIL != NULL){
        TAIL->next = newNode;
        newNode->previous = TAIL;
        TAIL = newNode;
    }
    else{
        return;
    }

}

Node *DLL::pop(){

    if(TAIL != NULL){
        Node *prevNode = TAIL->previous;
        TAIL = NULL;
        prevNode->next = NULL;
    }
    else{
        return;
    }

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
        newNode->previous = TAIL;
        TAIL = newNode;

    }

}

Node *createNode(){

    int val;
    while(1){

        cout << "\nPlease enter a value to assign to the new Node : ";
        cin >> val;
        if(val == 0){
            continue;
        }
        else{
            break;
        }
    }

    Node *newNode = new Node(val);
    return newNode;

}

void DLL::removeFirst(){

    if(HEAD->next == NULL){
        HEAD = NULL;
        TAIL = NULL;
    }
    else{
        Node *newHead = HEAD->next;
        HEAD = NULL;
        HEAD = newHead;
    }

}

void DLL::removeLast(){

    if(HEAD == NULL){
        return;
    }
    else if(HEAD->next == NULL){
        HEAD = NULL;
        TAIL = NULL;
    }
    else{
        Node *newTail = TAIL->previous;
        newTail->next = NULL;
        TAIL = NULL;
    }



}

Node *DLL::getFirst(){

    return HEAD;

}

Node *DLL::getLast(){

    return TAIL;

}

int DLL::size(){

    int count = 0;
    Node *tempHead = HEAD;
    while(tempHead->next != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;

}