#include <cmath>
#include <stdlib.h>
#include <iostream>
#include "Node.hpp"
using namespace std;

class DLL{

    Node *HEAD;
    Node *TAIL;

    public:

        DLL();

        Node *createNode();

        void push(Node *);

        Node *pop();

        void addFirst(Node *);

        void addLast(Node *);

        void removeFirst();

        void removeLast();

        Node *getFirst();

        Node *getLast();

        int size();

        Node *getNNode(int);

        Node *removeNNode(int);


};