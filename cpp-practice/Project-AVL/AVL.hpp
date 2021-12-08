#ifndef AVL_HPP_
#define AVL_HPP_

#include "TNode.hpp"

class AVL {
	TNode *root;  // root of tree
	bool debug; // for whether debug statements are printed out or not


public:
	AVL();
	AVL(bool debflag);
	AVL(string ab, string def);  //abbreviation and definition
	AVL(string ab, string def, bool debflag); 
                        // abbr, def, and boolean flag for debug
	bool insert(string ab, string def);
           // inserts based on ab, the abbreviation (the acronym)
           // creates a new node with teh abbreviation and 
           // definition and inserts it into the proper place in 
           // the tree
	TNode *find(string ab);
           //finds the abbreviation in the tree and returns the 
           // node with the abbreviation, null if it isn't in
           // the tree.

	void printTreeIO(TNode *n);
     // for first call of recursive function
	//think of this as outside the while loop(if comparing 
     //recursion to a while loop
	void printTreeIO();  
     // and this would be the recursive function
	//think of this as inside the while loop
	//(if comparing recursion to a while loop

	void printTreePre();
     // for first call of recursive function
	void printTreePre(TNode *n);
     // and this would be the recursive function

	void printTreePost();
     // for first call of recursive function
	void printTreePost(TNode *n);
     // and this would be the recursive function


	void clearTree();  
     // method for clearing all the nodes 
     // on a tree from the heap
	void clearTree(TNode *tmp);

	/****************** for AVL ***************************/
	void setHeight(TNode *n);
	int getBalance(TNode *tmp);
	TNode *rotateRight(TNode *tmp);
	TNode *rotateLeft(TNode *tmp);
};

#endif /* AVL_HPP_ */
