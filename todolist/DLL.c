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

    dNode *newNode = createNode(name,priority,hr,min);
    
    theList.totHrs += newNode->theTask->hr;
    theList.totMins += newNode->theTask->min;

    if(theList.first == NULL || theList.last == NULL){
        theList.first = newNode;
        theList.last = newNode;
    }
    else{
        if(priority == 3){
            
            theList.last->next = newNode;
            newNode->prev = theList.last;
            theList.last = newNode;
        }
        else{
            
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

int remove(int taskId){

    if(theList.first == NULL){
        return 0;
    }
    else{
        dNode *tempLast = theList.last;
        while(tempLast != NULL){
            if(tempLast->theTask->id == taskId){
                theList.totHrs -= tempLast->theTask->hr;
                theList.totMins -= tempLast->theTask->min;
                return 1;
            }
        }
        return 0;
    }
}

void moveUp(int tn){

    if(theList.first == NULL){
        return;
    }
    else{

        dNode *tempLast = theList.last;
        while(tempLast != NULL){

            if(tempLast->theTask->id == theList.first->theTask->id){
                // remove head
                tempLast->prev = theList.last;
                theList.first = tempLast->next;
                theList.first->prev = NULL;
                tempLast->next = NULL;
                theList.last = tempLast;
                tempLast->theTask->priority = tempLast->prev->theTask->priority;
                return;
            }
            if(tempLast->theTask->id == theList.last->theTask->id){
                // move up tail
                dNode *lastLastNode = tempLast->prev;
                tempLast->prev = tempLast->prev->prev;
                tempLast->prev->next = tempLast;
                tempLast->next->prev = lastLastNode;
                lastLastNode->prev = tempLast;
                tempLast->next = lastLastNode;
            }

            if(tempLast->theTask->id == tn){

                dNode *tempNode = tempLast->prev;
                tempLast->prev = tempLast->prev->prev;
                tempLast->prev->next = tempLast;
                tempLast->next->prev = tempNode;
                tempLast->next = tempNode;
                tempNode->prev = tempLast;
                tempLast->theTask->priority = tempLast->next->theTask->priority;
                
            }
            tempLast = tempLast->prev;

        }
        return;

    }


}

/*

Create move down method

*/

void printList(){

    dNode *tempFirst = theList.first;
    while(tempFirst != NULL){
        printTask(*(tempFirst->theTask));
        tempFirst = tempFirst->next;
    }

}

void printList(int p){

    dNode *tempFirst = theList.first;
    while(tempFirst != NULL){
        if(tempFirst->theTask->priority == p){
            printTask(*(tempFirst->theTask));
        }
        tempFirst = tempFirst->next;
    }

}

void addTime(int h, int m){

    while(m > 59){
        m -= 60;
        h++;
    }
    theList.totHrs += h;
    theList.totMins += m;

}


