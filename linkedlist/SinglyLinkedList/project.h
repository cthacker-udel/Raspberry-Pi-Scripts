#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct theNode{

    int value;
    struct theNode *next;


}node;


node *createNode();

node *push();

node *pop();

void insertNode(int);

void deleteNode(int);

void reverseList();

void displayList();

void sortList();

void addList();

void multiplyList();

void averageList();