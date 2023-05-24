#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct queueNode{

    int value;
    struct queueNode *next;
    struct queueNode *previous;

}node;

int max_size = 10;

int add(node *);

void increaseSize(int);

void clear();

int contains(node *);

int offer(node *);

node *peek();

node *poll();

int remove(node *);

int size();

int *toArray();

int isEmpty();

void sort();