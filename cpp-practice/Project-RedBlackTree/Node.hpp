#include <iostream>
#include <stdlib.h>
#include <stddef.h>
#include <string>
#include <vector>
#include <cmath>

class Node{

    int data; // int value for now, can be anything (double,float,string,etc)
    char color = 'B'; // R/B <--- default to black due to root
    Node *left;
    Node *right;
    Node *parent;
    friend class RB;

    public:

        Node(int);

        void setColor(char color);

        char getColor();

};