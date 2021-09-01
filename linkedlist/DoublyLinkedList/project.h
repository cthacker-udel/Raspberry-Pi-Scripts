#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct theNode{

    int val;
    struct theNode *next;
    struct theNode *prev;

}node;


void addNode(int);

int findFirstIndex(int);

int findLastIndex(int);

node *createNode();

node *createNodeV2(int);

void removeTail();

void removeHead();

int nodeCount();

