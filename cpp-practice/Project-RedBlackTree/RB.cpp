#include "RB.hpp"


RB::RB(){

    this->root = NULL;

}

void RB::insert(Node *newNode){

    if(this->root == NULL){
        // assign to root
        this->root = newNode;
    }
    else{

        Node *currNode = this->root;
        while(currNode != NULL){

            if(currNode->data > newNode->data){
                // move to left
                if(currNode->left == NULL){
                    // place here
                    currNode->left = newNode;
                    return;
                }
                insert(currNode->left);
            }
            else{
                if(currNode->right == NULL){
                    // place here
                    currNode->right = newNode;
                    return;
                }
                // move to right
                insert(currNode->right);
            }

        }

    }

}