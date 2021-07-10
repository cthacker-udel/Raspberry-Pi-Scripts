#include "DLL.h"

DLL theList;

void push(char *name, int priority, int hr, int min){

    if(theList.first == NULL || theList.last == NULL){
        dNode *newNode = (dNode *)malloc(sizeof(dNode));
        newNode->theTask = (task *)malloc(sizeof(task));
        strcpy(newNode->theTask->name,name);
        newNode->theTask->id = rand() % 3000;
        newNode->theTask->priority = priority;
        newNode->theTask->hr = hr;
        newNode->theTask->min = min;
        theList.first = newNode;
        theList.last = newNode;
    }
    else{

        dNode *newNode = (dNode *)malloc(sizeof(dNode));
        newNode->theTask = (task *)malloc(sizeof(task));
        strcpy(newNode->theTask->name,name);
        newNode->theTask->id = rand() % 3000;
        newNode->theTask->priority = priority;
        newNode->next = NULL;
        newNode->theTask->hr = hr;
        newNode->theTask->min = min;
        theList.last->next = newNode;
        newNode->prev = theList.last;

    }

}

