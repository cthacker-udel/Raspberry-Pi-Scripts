#include "Node.hpp"
#include <stdlib.h>
using namespace std;

/// @brief No-arg constructor, instantiates all fields to their default values
Node::Node()
{

    this->data = 0;
    this->right = NULL;
    this->left = NULL;
}

/// @brief One-arg constructor, instantiates data to the passed in value
/// @param theVal The value to instantiate the data field with
Node::Node(int theVal)
{

    this->data = theVal;
    this->right = NULL;
    this->left = NULL;
}

/// @brief Inserts a value into the tree, organized in binary tree structure
/// @param val The value to insert
/// @param newNode The node which serves as the iterative pointer
void Node::insertRec(int val, Node *newNode)
{

    if (this->root == NULL)
    {
        root = new Node(val);
        newNode = root;
    }
    else
    {
        if (newNode->right == NULL && newNode->data < val)
        {
            newNode->right = new Node(val);
        }
        else if (newNode->left == NULL && newNode->data > val)
        {
            newNode->left = new Node(val);
        }
        else if (newNode->data > val)
        {
            insertRec(val, newNode->left);
        }
        else if (newNode->data < val)
        {
            insertRec(val, newNode->right);
        }
    }
}
