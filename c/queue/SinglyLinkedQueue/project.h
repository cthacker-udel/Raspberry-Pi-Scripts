#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct queueNode{

    int value;
    struct queueNode *next;

}node;

int add(node *);

int increaseSize(int);

node *element();

int offer(node *);

node *peek();

node *poll();

node *removeHead();

int contains(node *);

int isEmpty();

int removeAll();

int size();

int clear();

