#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;


class Node{

    friend class Stack;
    int value;
    Node *next;

    public:

        Node();

        Node(int);


};