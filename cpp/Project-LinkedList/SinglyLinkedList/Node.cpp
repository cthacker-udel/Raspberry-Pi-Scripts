#include "Node.hpp"

Node::Node(){
    value = 10;
    next = NULL;
}

Node::Node(int newValue){
    value = newValue;
    next = NULL;
}

Node::~Node(){

    if(next != NULL){
        cout << "Cannot delete a node that contains a pointer to next that is not NULL, may result in data leak" << endl;
    }
    else{
        next = NULL;
        delete this;
    }

}