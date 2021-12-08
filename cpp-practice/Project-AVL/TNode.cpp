/*
 * TNode.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: 13027
 */

#include <iostream>
#include <string>
#include "TNode.hpp"
using namespace std;

TNode::TNode(string ab, string d, bool debflag) {
	left = NULL;
	right = NULL;
	parent = NULL;
	abbr = ab;
	def = d;
	height = 1;
}
TNode::TNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	abbr = "";
	def = "";
}
TNode::~TNode(){
	cout <<"Deleting "<<abbr<<": "<<def<<endl;
}
void TNode::printNode() {
	cout << "Abbr: " << abbr << ": ";
	cout << def << " ("<<height<<")"<<endl;
}
void TNode::printNode(bool debug) {
	cout << abbr << ": ";
	cout << def ;
	if (debug) {
		cout << " ("<<height<<")"<<endl;
	}
	else {
		cout << endl;
	}
}
