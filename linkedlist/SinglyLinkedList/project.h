#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct theNode{

    int value;
    struct theNode *next;


}node;


node *createNode();

void push(node *);

int pop();

int numNodes();

void insertNode(int);

void deleteNode(int);

void reverseList();

void displayList();

void sortList();

void addList();

void multiplyList();

void averageList();