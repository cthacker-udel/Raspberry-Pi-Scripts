#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Node{

    friend class SLL;
    int value;
    Node *next;

    public:

        Node();

        ~Node();

        Node(int);



};