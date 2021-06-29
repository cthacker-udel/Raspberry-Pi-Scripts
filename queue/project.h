#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct queueNode{

    int value;
    queueNode *next;

}node;

int add(node *);

node *element();

int offer(node *);

node *peek();

node *poll();

node *remove();

int contains(node *);

int isEmpty();

int removeAll();

int size();

int clear();

