#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct queueNode{

    int value;
    struct queueNode *next;
    struct queueNode *previous;

}node;