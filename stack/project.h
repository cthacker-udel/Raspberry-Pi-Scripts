#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct stackNode{

    int value;
    struct stackNode *next;

}node;

int push(int);

int pop(void);

int peek(void);

int empty(void);

int search(int);

void clear(void);

node *clone(void);

int get(int);

int size();

int lastIndexOf(int);

void toString();

int *toArray();

node *createNode(int);

void displayStack();

int sumStack();

int minusStack();

int multiplyStack();

int evenCount();

int oddCount();

int primeCount();

int positiveCount();

int negativeCount();
