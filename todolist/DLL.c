#include "DLL.h"

DLL theList;

dNode *createNode(char *taskName, int priority, int hr, int min){

    srand(time(NULL));
    dNode *newNode = (dNode *)malloc(sizeof(dNode));
    newNode->theTask = (task *)malloc(sizeof(task));
    newNode->theTask->name = (char *)malloc(sizeof(char) * strlen(taskName)+1);
    strcpy(newNode->theTask->name,taskName);
    newNode->theTask->priority = priority;
    newNode->theTask->hr = hr;
    newNode->theTask->min = min;
    newNode->theTask->id = rand() % 3142;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

}

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
        if(priority == 3){
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
        else{

            dNode *tempLast = theList.last;
            while(tempLast != NULL){

                if()

            }



        }
    }

}

task *pop(){

    if(theList.first == NULL){
        return NULL;
    }
    else{

        dNode *theNode = theList.first;
        theList.first = theList.first->next;
        task *theTask = theNode->theTask;
        free(theNode);
        return theTask;

    }





}

