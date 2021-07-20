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

void moveDown(int id){

    if(theList.first == NULL){
        // list is empty
        printf("\nThe list is empty\n");
    }
    if(theList.first->theTask->id == id){
        if(theList.first->next = NULL){
            // list consists of one node
            printf("\nThe list only consists of one node\n");
            return;
        }
        else{
            if(theList.first->next->theTask->priority > theList.first->theTask->priority){
                theList.first->theTask->priority = theList.first->next->theTask->priority;
            }
            dNode *firstNext = theList.first->next;
            firstNext->prev = NULL;
            theList.first->next = firstNext->next;
            firstNext->next->prev = theList.first;
            firstNext->next = theList.first;
            theList.first->prev = firstNext;
            theList.first = firstNext;
            return;
        }
    }
    if(theList.last->theTask->id == id){

        if(theList.last->prev == NULL){
            // list only consists of one node
            printf("\nThe list only consists of one node\n");
        }
        else{
            if(theList.first->theTask->priority < theList.last->theTask->priority){
                theList.last->theTask->priority = theList.first->theTask->priority;
            }
            dNode *lastPrev = theList.last->prev;
            theList.first->prev = theList.last;
            theList.last->prev->next = NULL;
            theList.last->prev = NULL;
            theList.last->next = theList.first;
            theList.last = lastPrev;
            return;

        }

    }

}

void changePriority(int taskid, int newP){

    if(theList.last == NULL){
        printf("\nTrying to access an empty list");
        return;
    }

    dNode *lastTemp = theList.last;

    while(lastTemp != NULL && lastTemp->theTask->id != taskid){
        lastTemp = lastTemp->prev;
    }

    if(lastTemp == NULL){
        printf("\nUnable to locate task, please re-enter id and new priority\n");
        return;
    }

    lastTemp->theTask->priority = newP;
    // then remove task
    if(lastTemp == theList.first && lastTemp == theList.last){
        // list only has one node
        return;
    }

    if(lastTemp == theList.first){

        // re assign head first
        lastTemp->next->prev = NULL;
        theList.first = lastTemp->next;
        lastTemp->next = NULL;

    }

    if(lastTemp == theList.last){

        // re assign tail
        lastTemp->prev->next = NULL;
        theList.last = lastTemp->prev;
        lastTemp->prev = NULL;

    }

    dNode *tempLast = theList.last;

    while(tempLast != NULL && tempLast->theTask->priority > tempLast->theTask->priority){
        tempLast = tempLast->prev;
    }

    tempLast->next->prev = lastTemp;
    lastTemp->next = tempLast->next;
    lastTemp->prev = tempLast;
    tempLast->next = lastTemp;


    // re-assignment complete


    /*

    1 ---  1
    2      2
    2      2
    3      2
           3

    <-- 2

    1   --1
    2   --2
    2   --2
    3   --3
        --3

    <--- 3


    1   --1
    2   --1
    2   --2
    3   --2
        --3

    <--- 1


    */




}

void listDuration(int *th, int *tm, int p){

    dNode *tempLast = theList.last;
    while(tempLast->prev != NULL){

        if(tempLast->theTask->priority == p){
            *th += tempLast->theTask->hr;
            *tm += tempLast->theTask->min;
        }

    }

    while(tm >= 60){
        *th += 1;
        *tm -= 60;
    }


}

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

void removeTime(int h, int m){

    while(m > 59){
        m -= 60;
        h++;
    }
    theList.totHrs -= h;
    theList.totMins -= m;

}


