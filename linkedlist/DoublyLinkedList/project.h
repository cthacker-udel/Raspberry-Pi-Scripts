#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct theNode{

    int val;
    struct theNode *next;
    struct theNode *prev;

}node;


void addNode(int);

void addHead(int);

void addTail(int);

int findFirstIndex(int);

int findLastIndex(int);

node *createNode();

node *createNodeV2(int);

void removeTail();

void removeHead();

int nodeCount();

int removeNode(int);

void insert(int,int);

void moveUp(int);

void moveDown(int);

int exists(int);

int occurence(int);

int* indexes(int);

int isUnique(int);

int isRepeating(int);

int swapValue(int,int);

int isPrime(int);

int evenCount();

int oddCount();

int primeCount();

int isSortedAscending();

int isSortedDescending();

void sort();

int *toIntArray();

void deleteList();

void weightedEvenOrOdd();

int *bubbleSortArr(int *, int);

int abundantNumberCount();

int deficientNumberCount();
