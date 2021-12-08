#include <stdlib.h>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Node{

    friend class DLL;
    int value;
    Node *next;
    Node *previous;

    public:

        Node();

        Node(int);



};