
#include <stdlib.h>
/**************************************************************/
/* Part 1:                                                    */ /* Name the methods below with the correct name from the list */
/* below:                                                     */
/*    find                                                    */
/*    insert                                                  */
/*    printTreePre                                            */
/*    printTreeIO                                             */
/*    printTreePost                                           */
/*                                                            */
/* Once you have named them, move them to into the AVL Class  */
/* Definition file (the .cpp), below the constructors (scroll */
/* down and you'll see the constructors)                      */
/**************************************************************/
/********************* method 1 *******************************/
void AVL::printTreePost(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		tmp->printNode(debug);
		(tmp->right);
	}
}
/********************* method 2 *******************************/
void AVL::printTreePre(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		(tmp->left);
		(tmp->right);
		tmp->printNode(debug);
	}
}
/********************* method 3 *******************************/
TNode *AVL::find(string a) {
	if (root == NULL) {
		if (debug) {
		   cout << "root is null " << a << endl;
		}
		return NULL;
	}
	else {
		TNode *tmp = root;
		while (tmp != NULL) {
			if (debug) {
				cout <<tmp->abbr << " and "<<a << endl;
			}
			if (a < tmp->abbr) {
				if (debug) {
					cout << "going left " << endl;
				}
				if (tmp->left == NULL) {
					return NULL;
				}
				else {
					tmp=tmp->left;
				}
			}
			else if (a > tmp->abbr) {
				if (debug) {
					cout << "going right " << endl;
				}
				if (tmp->right == NULL) {
					return NULL;
				}
				else {
					tmp=tmp->right;
				}
			}
			else {
				if (debug) {
					//cout << " in " << ct << endl;
				}
				return tmp;
			}
		}
	}
	return NULL;
}
/********************* method 4 *******************************/
void AVL::printTreeIO(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		(tmp->left);
		tmp->printNode(debug);
		(tmp->right);
	}
}
/********************* method 5 *******************************/
bool AVL::insert(string ab, string d) {
	TNode *newnode = new TNode(ab, d, debug);

	if (root == NULL) {		
		if (debug ) {
		    cout << "root NULL" << endl;
		}
		root = newnode;
		return true;
	}
	else {
		TNode *tmp = root;
		while (tmp != NULL){
			if (newnode->abbr < tmp->abbr) {
				if (tmp->left == NULL) {
					tmp->left = newnode;
					tmp->left->parent = tmp;
					return true;
				}
				else {
					tmp=tmp->left;
				}
			}
			else if (newnode->abbr > tmp->abbr) {
				if (tmp->right == NULL) {
					tmp->right = newnode;
					tmp->right->parent = tmp;
					return true;
				}
				else {
					tmp=tmp->right;
				}
			}
			else {
				return false;
			}
		}
	}
	return false;
}
/*******************End of Naming Methods*********************/
/* Now move the methods above (with the blanks filled in     */
/* correctly below the constructors, below                   */
/*************************************************************/

/*************************************************************/
/*Part 2                                                     */
/* Now you must do two things:                               */
/* 1) add a count to the find method such that it counts how */
/*    many comparisions you do every time you find an        */
/*    abbreviation; and                                      */
/* 2) in the insert method, add a call to the setHeight      */
/*    method in the appropriate place(s) so that after you   */
/*    inserted, the setHeight method adjusts the heights of  */
/*    the inserted node's ancestors.
/*************************************************************/

/*************************************************************/
/*Part 3                                                     */
/* Write the methods (in red, below) that are part of the    */
/* AVL Tree class                                            */
/*************************************************************/

#include "AVL.hpp"

#include <iostream>
#include <stdlib.h>
using namespace std;

/*************************************************************/
/* Constructors 
   debug is a boolean flag that, if set, will result in the 
   printing of a number of debug statements.  If it isn't
   set, the code will print without the debug statements.
*/
AVL::AVL() {
	root = NULL;
	debug = false;
}

AVL::AVL(bool debflag) {
	root = NULL;
	debug = debflag;
}

AVL::AVL(string ab, string d) {
	root = new TNode(ab, d, false);
	debug = false;

}

AVL::AVL(string ab, string d, bool debflag) {
	root = new TNode(ab, d, debflag);
	debug = debflag;

}
/*************************************************************/
/*Methods you have to write                                  */
/*These methods are specifically for an AVL tree, which means*/
/*they involve keeping track of a node's height and balance, */
/*and rotating when a node becomes unbalanced                */
/*WATCH OUT FOR:                                             */
/*   NULL nodes (they don't have fields                      */
/*   Attaching parents properly, especially during rotations */
/*************************************************************/
int AVL::getBalance(TNode *tmp) {
/* method that finds the balance of a node tmp and returns that balance as an int
*/
}

TNode *AVL::rotateRight(TNode *tmp) {
/* rotates right around node tmp and returns the node rotated up.  Note: this method must reset the heights of the node rotated down and the nodes rotated up, and you must reset the heights of all nodes that are ancestors of the node rotated down.  You will also need to reattach the newly rotated up node to the rest of the tree either in this method or in setheights.
*/
}

TNode *AVL::rotateLeft(TNode *tmp) {
/* rotates down around node tmp and returns the node rotated up.  Note: this method must reset the heights of the node rotated down and the nodes rotated up, and you must reset the heights of all nodes that are ancestors of the node rotated down. You will also need to reattach the newly rotated up node to the rest of the tree either in this method or in setheights.
*/
}

void AVL::setHeight(TNode *tmp) {
/*
This method sets the height of tmp and then of all the ancestors of tmp.  It stops when the height of a node does not change. Note that this method most likely calls getBalance and possibly the rotate methods, and may even set the newly rotated up node's parent attachement, although you could do that in the rotate method.
*/ 
}
void AVL::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

void AVL::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void AVL::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void AVL::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void AVL::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}