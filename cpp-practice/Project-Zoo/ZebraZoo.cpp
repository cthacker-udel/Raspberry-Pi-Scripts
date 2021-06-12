#include "ZebraZoo.hpp"

ZebraZoo::ZebraZoo(){
	
	name = "Generic Zebra Zoo";
	occupants = 0;

}

ZebraZoo::ZebraZoo(string newName){

	name = newName;
	occupants = 0;

}

int ZebraZoo::getNumberOfOccupants(){
	return occupants;
}


void ZebraZoo::addZebra(Zebra newZebra){
	zebras.push_back(newZebra);
	occupants++;
}


