#include "Gorilla.hpp"



Gorilla::Gorilla(){
	name = "Harombe";
	age = 20;
	height = 400;
}

Gorilla::Gorilla(string newName){
	name = newName;
	age = 20;
	height = 400;
}

Gorilla::Gorilla(string newName, int newAge){
	name = newName;
	age = newAge;
	height = 400;
}

Gorilla::Gorilla(string newName, int newAge, int newHeight){
	name = newName;
	age = newAge;
	height = newHeight;
}


int Gorilla::getAge(){
	return age;
}

string Gorilla::getName(){
	return name;
}

int Gorilla::getHeight(){
	return height;
}

void Gorilla::setAge(int newAge){
	age = newAge;
}

void Gorilla::setHeight(int newHeight){
	height = newHeight;
}

void Gorilla::setName(string newName){
	name = newName;

}


string Gorilla::toString(){
	string origString;
	origString += name + " has an age of " + to_string(age) + " and a height of " + to_string(height) + " cm";
	return origString;
}
