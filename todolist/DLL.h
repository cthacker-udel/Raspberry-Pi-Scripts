#include "DNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct theList{

    dNode *first;
    dNode *last;
    int numTasks;
    int totHrs;
    int totMins;

}DLL;

void push(char *, int, int, int);

dNode *createNode(char *,int,int,int);

task *pop();

int remove(int);

void moveUp(int);

void moveDown(int);

void changePriority(int,int);

void listDuration(int *th, int *tm, int p);

void printList();

void printList(int);

void addTime(int,int);

void removeTime(int,int);