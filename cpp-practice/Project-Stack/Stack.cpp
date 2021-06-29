#include "Stack.hpp"

Stack::Stack(){

    head = NULL;

}

int Stack::size(){

    int count = 0;
    Node *tempHead = head;
    while(tempHead != NULL){
        tempHead = tempHead->next;
        count++;
    }
    return count;

}

Node Stack::push(Node *newNode){

    Node tempNode = *newNode;
    Node *tempHead = head;
    newNode->next = head;
    head = newNode;
    return tempNode;

}

Node Stack::pop(){

    Node *tempHead = head;
    while(tempHead->next != NULL){
        tempHead = tempHead->next;
    }
    return *tempHead;

}

Node Stack::peek(){

    if(head != NULL){
        return *head;
    }
    else{
        return NULL;
    }

}

bool Stack::empty(){

    int theSize = size();
    return theSize == 0? true: false;

}

int Stack::search(Node *theNode){

    int index = 0;
    Node *tempHead = head;
    while(tempHead != NULL){
        if(tempHead == theNode){
            return index;
        }
        index++;
        tempHead = tempHead->next;
    }
    return -1;

}