#ifndef TNODE_HPP_
#define TNODE_HPP_
#include <iostream>
using namespace std;

class TNode{
	friend class AVL;
	friend class Translator;
	TNode *left;
	TNode *right;
	TNode *parent;
	string abbr; // the acronym or slang
	string def;  //its definition
	int height;  //the height of a node up from its farthest leaf.
public:
	TNode(string ab, string def, bool debflag);
	TNode();  // I always make a blank constructor, for variables I don't want to
	//initialize right away
	~TNode();
	void printNode();
	void printNode(bool debflag);
};



#endif /* TNODE_HPP_ */
