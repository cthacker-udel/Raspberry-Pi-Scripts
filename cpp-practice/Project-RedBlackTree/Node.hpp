#include <iostream>
#include <stdlib.h>
#include <stddef.h>
#include <string>
#include <vector>
#include <cmath>

class Node{

    int data; // int value for now, can be anything (double,float,string,etc)
    char color; // R/B
    Node *left;
    Node *right;
    Node *parent;

    public:

        Node(int);

        void setColor(char color);

};