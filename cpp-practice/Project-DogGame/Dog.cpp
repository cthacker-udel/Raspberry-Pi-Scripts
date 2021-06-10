#include "Dog.hpp"
#include <iostream>
using namespace std;

Dog::Dog(string newName){

	name = newName;
	strength = 50;
	x = 0;
	y = 0;

}

Dog::Dog(){

	name = "fluffy";
	strength = 50;
	x = 0;
	y = 0;

}

void Dog::die(){

	cout << "ACK!!! Your dog has died" << endl;

}

bool Dog::changeStrength(int amt){

	strength += amt;
	return strength > 0;

}

void Dog::printDog(){

	cout << name << " has " << strength << " strength left" << endl;

}

void Dog::won(){

	cout << "You have reached the end of the maze! You have won!" << endl;

}

void Dog::reset(){

	strength = 50;
	x = 0;
	y = 0;

}

