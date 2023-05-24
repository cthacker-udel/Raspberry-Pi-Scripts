#include "Translator.hpp"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


Translator::Translator(string name,bool debflag) {
	fn = name;
	debug = debflag;
	tree = new AVL(debflag);
	readFile();
}


void Translator::Interface() {
	char c = 'a';
	while (c != 'q') {
		cout <<endl<<"****************************************************"<<endl;
		cout <<"Choose Option:\n  a\ttranslate sentence\n  b\tfind acronym\n  c\tadd an acronym and definition\n  d\tprint tree\n  q\tquit"<< endl;
		cin >> c;
		switch (c) {
			case 'a': {
				translateSentence();
				break;
			}
			case 'b':{
				string acr;
				cout << "Enter Acronym: "<<endl;
				cin >> acr;
				TNode *t = tree->find(acr);
				if (t != NULL) {
					t->printNode();
				}
				else {
					cout << acr << " not found in database"<<endl;
				}
				break;
			}
			case 'c':{
				string acr;
				cout << "Enter Acronym: "<<endl;
				cin >> acr;
				cout << "Enter the definition: " << endl;
				cin.ignore();
				string def;
				getline(cin, def);

				if (tree->insert(acr,def)) {
					cout << endl <<acr << ":\t" << def<< "inserted successfully "<<endl;
				}
				else {
					TNode *t = tree->find(acr);
					t->printNode();
					cout << "... already in tree with " << endl;
				}
				break;
			}
			case 'd': {
				cout << "Choose a for pre, b for in, or c for post-order\t";
				char k;
				cin >> k;
				cout << endl;
				cout << "************************************************"<<endl;
				if (k == 'a') {
					cout << "*********** Printing Tree Pre Order ************"<<endl;
					cout << "************************************************"<<endl;
					tree->printTreePre();
				}
				else if (k == 'b') {
					cout << "*********** Printing Tree In Order *************"<<endl;
					cout << "************************************************"<<endl;
					tree->printTreeIO();
				}
				if (k == 'c') {
					cout << "*********** Printing Tree Post Order ***********"<<endl;
					cout << "************************************************"<<endl;
					tree->printTreePost();
				}

				break;
			}
			case 'q': {
				cout << "GB"<<endl;
				break;
			}
		}
	}
}
TNode *Translator::getAcr() {
	cout << "Enter Acronym: "<<endl;
	string acr;
	cin >>acr;
	TNode *t = tree->find(acr);
	if (t == NULL) {
		cout << acr <<" not found in database.  " << endl;
	}
	else {
		TNode *s = tree->find(acr);
		s->printNode();
	}
	return t;
}
void Translator::translateSentence() {
	const char* WhiteSpace = " \t\v\r\n.?!";
	//const char* EndChar = ":\t\n";
	string trans= "";
	string sentence;
	string acr;
	TNode *t;
	cout << "Enter sentence to translate (you old person):" << endl;
	cin.ignore();
	getline(cin, sentence);
	size_t start = sentence.find_first_not_of(WhiteSpace);
	cout << "start is " <<start <<endl;
	int len;
	if (start > 0) {
		len = sentence.length();
		sentence = sentence.substr(start,len-start+1);
	}
	size_t end;
	len = sentence.length();
	while (len > 0) {
		end = sentence.find_first_of(WhiteSpace);
		if (end > 0) {
			acr = sentence.substr(0,end);
			if (acr != "") {
				t = tree->find(acr);
				if (t != NULL) {
					trans += t->def;
				}
				else {
					if (debug) {
						cout << "No translation for " << acr << endl;
					}
					trans += acr;
				}
				if (debug) {
					trans += " ";
				}
			}
			len = sentence.length();
			//cout << "Here" << endl;
			if (len > end) {
				sentence = sentence.substr(end,len-end+1);
				//cout <<"Here 2" << endl;
				len = sentence.length();
				//cout <<"Here 3 " << endl;
				if (len > 0) {
					start = sentence.find_first_not_of(WhiteSpace);
					//cout << "Here 4" << endl;
					sentence = sentence.substr(start,len-start+1);
					//cout << "Here 5" << endl;
				}
			}
			else len = 0;
			cout << trans << endl;
		}

	}
	cout <<  trans << endl;
	return;
}
string Translator::strip(string s, string def) {
	const char* WhiteSpace = " \t\v\r\n";
	//const char* EndChar = ":\t\n";
	def = "";
 	size_t start = s.find_first_not_of(WhiteSpace);
	int len = s.length();
	def = s.substr(start,len-start+1);
	return def;
}
void Translator::readFile() {
	ifstream file(fn.c_str());
	string acr;
	string phrase;
	string def;
	file >> acr;
	while (!file.eof()) {
		getline(file,phrase);
		phrase = strip(phrase, def);
		if (phrase == "") {
			cout << "Warning: no def for "<<acr<<endl;
		}
		if (debug) {
			cout << "readFile:  " << acr<<":"<<phrase<<endl;
		}
		tree->insert(acr,phrase);
		file >> acr;
	}
	return;
}


