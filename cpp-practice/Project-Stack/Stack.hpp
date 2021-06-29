#include <string>
#include <stdlib.h>
#include <cmath>
#include "Node.hpp"
using namespace std;

class Stack{

    Node *head;

    public:

        Stack();

        int size();

        Node *push(Node *);

        Node *pop();

        Node *peek();

        bool empty();

        int search(Node *);

        Node *clone();

        bool contains(Node *);

        void printStack();




};