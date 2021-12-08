#include "Node.hpp"
#include <stdlib.h>
using namespace std;


Node::Node(){

    this->data = 0;
    this->right = NULL;
    this->left = NULL;

}

Node::Node(int theVal){

    this->data = theVal;
    this->right = NULL;
    this->left = NULL;

}

bool Node::insertRec(int val, Node *newNode){

    if(this->root == NULL){
        root = new Node(val);
        newNode = root;
    }
    else{
        if(newNode->right == NULL && newNode->data < val){
            newNode->right = new Node(val);
        }
        else if(newNode->left == NULL && newNode->data > val){
            newNode->left = new Node(val);
        }
        else if(newNode->data > val){
            insertRec(val,newNode->left);
        }
        else if(newNode->data < val){
            insertRec(val,newNode->right);
        }
    }

}
