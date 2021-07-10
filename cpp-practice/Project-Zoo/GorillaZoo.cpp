#include "GorillaZoo.hpp"

GorillaZoo::GorillaZoo(){
	occupancy = 0;
}

GorillaZoo::GorillaZoo(string newName){
	name = newName;
	occupancy = 0;
}

int GorillaZoo::getOccupancy(){
	return occupancy;
}

vector<Gorilla> GorillaZoo::getGorillas(){
	return gorillas;
}

void GorillaZoo::addGorilla(Gorilla newGorilla){
	gorillas.push_back(newGorilla):
}
