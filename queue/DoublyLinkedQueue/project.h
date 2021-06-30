#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include <stdbool.h>

int MAX_SIZE = 10;

node *HEAD = NULL;
node *TAIL = NULL;


typedef struct queueNode{

    int value;
    struct queueNode *next;
    struct queueNode *previous;

}node;

node *craftNode();

int *add(node *);

node *element();

int offer(node *);

node *peek();

node *poll();

node *removeHead();

int increaseSize(int);

int contains(node *);

int isEmpty();

int removeAll();

int size();

int clear();

int *toArray();