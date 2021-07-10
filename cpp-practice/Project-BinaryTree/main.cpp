#include "Node.cpp"

int main(void){

    Node *root = new Node();
    root->right = new Node(10);
    root->left = new Node(20);
    root->right->left = new Node(30);

}