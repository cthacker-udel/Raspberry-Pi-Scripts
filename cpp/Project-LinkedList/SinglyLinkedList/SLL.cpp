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

void SLL::addFirst(Node *newNode){

    if(this->first != NULL){
        return;
    }
    else{
        this->first = newNode;
    }

}

void SLL::addLast(Node *newNode){
    push(newNode);
}

void SLL::removeFirst(void){

    if(this->first == NULL){
        return;
    }
    else if(this->first->next = NULL){
        first = NULL;
        last = NULL;
    }
    else{
        Node *nextNode = first->next;
        first = NULL;
        first = nextNode;
    }

}

void SLL::removeLast(){

    if(this->last == NULL){
        return;
    }
    else if(first == last){
        first = NULL;
        last = NULL;
    }
    else{

        Node *tempHead = first;
        while(tempHead->next != last){
            tempHead = tempHead->next;
        }
        tempHead->next = NULL;
        last = NULL;
        last = tempHead;

    }

}

Node *SLL::getFirst(){

    return this->first;

}

Node *SLL::getLast(){

    return this->last;

}

int SLL::size(){

    int count = 0;
    Node *tempHead = this->first;
    
    while(tempHead != NULL){
        tempHead = tempHead->next;
        count++;
    }

    return count;
}

Node *SLL::getNNode(int n){

    int index = 0;
    int numberOfNodes = size();
    if(numberOfNodes == 0){
        return NULL;
    }
    else if(n >= numberOfNodes){
        return this->last;
    }
    else{

        Node *tempHead = this->first;
        while(tempHead != NULL){
            if(index == n){
                return tempHead;
            }
            else{
                tempHead = tempHead->next;
            }
        }
        return last;

    }

}

Node *SLL::removeNNode(int n){

    int count = 0;
    int numberOfNodes = size();
    if(numberOfNodes == 0){
        return NULL;
    }
    else if(n >= numberOfNodes){
        removeLast();
    }
    else if(n == 0){
        removeFirst();
    }
    else{

        Node *tempHead = first;
        Node *prevNode;
        while(tempHead != NULL){
            prevNode = tempHead;
            tempHead = tempHead->next;
            if(count == 0){

            }
        }

    }

}

