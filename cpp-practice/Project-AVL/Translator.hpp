#ifndef TRANSLATOR_CPP_
#define TRANSLATOR_CPP_
#include <iostream>
#include <stdlib.h>
#include "AVL.hpp"
using namespace std;

class Translator {
	string fn;
	bool debug;
public:
	Translator(string fn, bool debflag);
	AVL *tree;
	void readFile();
	TNode *getAcr();
	void translateSentence();
	string strip(string acr, string def);

	void Interface();
//	void addPhrases();
//	void deletePhrases();
//	void printPhrases();

};

#endif /* TRANSLATOR_CPP_ */
