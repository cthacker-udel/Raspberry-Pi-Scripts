#include "MonkeyZoo.hpp"
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

MonkeyZoo::MonkeyZoo(){
	name = "The Monkey Zoo";
	occupants = 0;
}


MonkeyZoo::MonkeyZoo(string newName){
	name = newName;
	occupants = 0;
}

int MonkeyZoo::getNumberOfOccupants(){
	return occupants;
}

string MonkeyZoo::getName(){
	return name;
}

vector<Monkey> MonkeyZoo::getMonkeys(){
	return monkeys;
}

void MonkeyZoo::addMonkey(Monkey newMonkey){
	monkeys.push_back(newMonkey);
}

void MonkeyZoo::displayMonkeys(){
	if(monkeys.size() == 0){
		cout << "We have no monkeys currently occupying " << name << " at the moment" << endl;
	}
	else{
		cout << "The Zoo : " << name << " contains " << monkeys.size() << " monkeys " << endl;
		for(int i = 0; i < monkeys.size(); i++){
			string printString;
			printString += "-----------------------\n";
			printString += "Monkey : " + ++i + "\n";
			printString += monkeys[i].toString();
			printString += "\n-----------------------\n";
			cout << printString << endl;
		}
	}
}
