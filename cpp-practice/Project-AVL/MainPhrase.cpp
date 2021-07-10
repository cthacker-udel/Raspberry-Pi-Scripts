#include <iostream>
#include "Translator.hpp"
using namespace std;

int main() {
/************Part 1 - for testing left rotations *****/
//	Translator *tree = new Translator("Testleft.txt",true);
//	cout << endl<<endl<<"************************************" << endl;
//	cout <<"Preorder:" << endl;
//	tree->tree->printTreePre();
//	cout << endl<<endl<<"************************************" << endl;
//	cout <<"Inorder:" << endl;
//	tree->tree->printTreeIO();
//	cout << endl<<endl<< "************************************" << endl;
//	cout <<"Postorder:" << endl;
//	tree->tree->printTreePost();
//	cout << endl<<endl<< "************************************" << endl;
//	tree->tree->clearTree();
//
//	delete tree;
/**********End of Part 1 *************************/


/***** Part 2 testing the right rotations *****/
//	Translator *tree = new Translator("TestRight.txt",true);
//	cout << endl<<endl<<"************************************" << endl;
//	cout <<"Preorder:" << endl;
//	tree->tree->printTreePre();
//	cout << endl<<endl<<"************************************" << endl;
//	cout <<"Inorder:" << endl;
//	tree->tree->printTreeIO();
//	cout << endl<<endl<< "************************************" << endl;
//	cout <<"Postorder:" << endl;
//	tree->tree->printTreePost();
//	cout << endl<<endl<< "************************************" << endl;
//	tree->tree->clearTree();
//
//	delete tree;
/************End of Part 2 **********************/

/***** Part 3 testing the right-left rotations *****/
//	Translator *tree = new Translator("TestRightLeft.txt",true);
//	cout << endl<<endl<<"************************************" << endl;
//	cout <<"Preorder:" << endl;
//	tree->tree->printTreePre();
//	cout << endl<<endl<<"************************************" << endl;
//	cout <<"Inorder:" << endl;
//	tree->tree->printTreeIO();
//	cout << endl<<endl<< "************************************" << endl;
//	cout <<"Postorder:" << endl;
//	tree->tree->printTreePost();
//	cout << endl<<endl<< "************************************" << endl;
//	tree->tree->clearTree();
//
//	delete tree;
/****************End of Part 3 **************************/



/***** Part 4 testing the left-right rotations *****/
//	Translator *tree = new Translator("TestLeftRight.txt",true);
//	cout << endl<<endl<<"************************************" << endl;
//	cout <<"Preorder:" << endl;
//	tree->tree->printTreePre();
//	cout << endl<<endl<<"************************************" << endl;
//	cout <<"Inorder:" << endl;
//	tree->tree->printTreeIO();
//	cout << endl<<endl<< "************************************" << endl;
//	cout <<"Postorder:" << endl;
//	tree->tree->printTreePost();
//	cout << endl<<endl<< "************************************" << endl;
//	tree->tree->clearTree();
//	delete tree;
/*********End of Part 4 ***********************/

/*****And now for the big tree!!!  Part 7 *************/
	Translator *tree = new Translator("abbr.txt", true);
	tree->tree->printTreeIO();
	cout << endl<<endl<< "************************************" << endl;
	tree->Interface();
	return 0;
}


