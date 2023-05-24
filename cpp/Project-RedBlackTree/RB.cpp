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
                    if(currNode->color == 'R'){
                        // red node, make sure insertion node is black
                        newNode->setColor('B');
                    }
                    if(currNode->color == 'B'){
                        newNode->setColor('R');
                    }
                    currNode->left = newNode;
                    return;
                }
                insert(currNode->left);
            }
            else{
                if(currNode->right == NULL){
                    // place here
                    currNode->right = newNode;
                    if(currNode->color == 'R'){
                        newNode->setColor('B');
                    }
                    if(currNode->color == 'B'){
                        newNode->setColor('R');
                    }
                    return;
                }
                // move to right
                insert(currNode->right);
            }

        }

    }

}