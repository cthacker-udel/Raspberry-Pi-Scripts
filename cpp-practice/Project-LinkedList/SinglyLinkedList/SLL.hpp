#include "Node.hpp"

class SLL{

    Node *first;
    Node *last;

    public:
        
        SLL();

        SLL(Node *);

        void push(Node *);

        Node *pop();

        void addFirst(int);

        void addLast(int);

        void removeFirst();

        void removeLast();

        Node *getFirst();

        Node *getLast();

        Node *getNNode(int);

        Node *removeNNode(int);

};