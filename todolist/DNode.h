#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Task.h"

typedef struct theNode{

    task *theTask;
    struct theNode *next;
    struct theNode *prev;

}dNode;