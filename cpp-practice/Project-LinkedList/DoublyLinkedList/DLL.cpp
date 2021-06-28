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