class Node{

    int data;

    public:
    
        Node *left;
        Node *right;
        Node *parent;
        Node *root;

        Node();

        Node(int);

        bool insertRec(int, Node *);

};