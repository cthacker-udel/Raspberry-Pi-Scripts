#include "Node.hpp"

class SLL{

    Node *first;
    Node *last;

    public:
        
        SLL();

        SLL(Node *);

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