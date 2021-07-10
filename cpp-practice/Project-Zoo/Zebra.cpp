#include "Zebra.hpp"


Zebra::Zebra(){
	legs = 4;
	age = 20;
	roar = "ROAR";
}


Zebra::Zebra(int newLegs){
	legs = newLegs;
	age = 20;
	roar = "ROAR";
}

Zebra::Zebra(int newLegs, int newAge){
	legs = newLegs;
	age = newAge;
	roar = "ROAR";
}

Zebra::Zebra(int newLegs, int newAge, string newRoar){
	legs = newLegs;
	age = newAge;
	roar = newRoar;
}

Zebra::Zebra(int newLegs, int newAge, string newRoar, string newName){
	legs = newLegs;
	age = newAge;
	roar = newRoar;
	name = newName;
}

Zebra::Zebra(string newName){
	legs = 4;
	age = 20;
	roar = "ROAR";
	name = newName;
}

void Zebra::setAge(int newAge){
	age = newAge;
}

void Zebra::setRoar(string newRoar){
	roar = newRoar;
}

void Zebra::setName(string newName){
	name = newName;
}

int Zebra::getLegNumber(){
	return legs;
}

int Zebra::getAge(){
	return age;
}


int Zebra::getRoar(){
	return roar;
}

string Zebra::getName(){
	return name;
}
