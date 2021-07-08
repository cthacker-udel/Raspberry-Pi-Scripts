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
