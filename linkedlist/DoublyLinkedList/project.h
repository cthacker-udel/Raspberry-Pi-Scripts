#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct theNode{

    int val;
    struct theNode *next;
    struct theNode *prev;

}node;


void addNode(int);

void findFirstIndex(int);

void findLastIndex(int);

node *createNode();

node *createNodeV2(int);

void removeTail();

void removeHead();

