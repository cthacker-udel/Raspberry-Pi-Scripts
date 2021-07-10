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
        dNode *newNode = createNode(name,priority,hr,min);
        theList.first = newNode;
        theList.last = newNode;
    }
    else{
        if(priority == 3){
            dNode *newNode = createNode(name,priority,hr,min);
            theList.last->next = newNode;
            newNode->prev = theList.last;
            theList.last = newNode;
        }
        else{
            
            dNode *newNode = createNode(name,priority,hr,min);
            dNode *tempLast = theList.last;
            while(tempLast != NULL){

                if(tempLast->theTask->priority == newNode->theTask->priority){

                    newNode->prev = tempLast;
                    newNode->next = tempLast->next;
                    tempLast->next->prev = newNode;
                    return;

                }

            }
            newNode->next = theList.first;
            theList.first = newNode;

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

