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