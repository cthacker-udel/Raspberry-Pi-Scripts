#include "Node.hpp"


Node::Node(int val){

    this->data = val;

}


void Node::setColor(char color){

    this->color = color;

}


char Node::getColor(){

    return this->color;

}