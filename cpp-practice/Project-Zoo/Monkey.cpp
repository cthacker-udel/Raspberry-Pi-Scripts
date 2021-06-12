#include "Monkey.hpp"
#include <string>
#include <cmath>
#include <stdlib.h>
#include <stddef.h>
#include <iostream>

using namespace std;



Monkey::Monkey(){
	name = "George";
	numBananasEaten = 10;
}

Monkey::Monkey(string newName){
	name = newName;
	numBananasEaten = 10;
}

bool Monkey::isHappy(){
	return numBananasEaten > 20;
}

int Monkey::getNumberOfBananasEaten(){
	return numBananasEaten;
}

string Monkey::getName(){
	return name;
}

string Monkey::toString(){
	string theString;
	theString += "Name : " + name + "\nNumber of Bananas Eaten : " + numBananasEaten;
	return theString;
}
