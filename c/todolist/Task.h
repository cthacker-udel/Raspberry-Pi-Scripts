#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct theTask{

    char *name;
    int id;
    int rank;
    int hr;
    int min;
    int priority;

}task;


void printTask(task);