#include "SLL.hpp"
#include <stdlib.h>
using namespace std;


SLL::SLL(){

    first = NULL;
    last = NULL;

}

SLL::SLL(Node *newNode){

    first = newNode;
    last = newNode;

}

