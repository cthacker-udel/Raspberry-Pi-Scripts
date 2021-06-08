#include "District.hpp"

District::District(){
    name = "Thacker Ville";
    founded = 1800;
    population = 1;
}


District::District(string newName){
    name = newName;
    founded = 1800;
    population = 1;
}

District::District(string newName, int newPopulation){
    name = newName;
    founded = 1800;
    population = newPopulation;
}


District::District(string newName, int newPopulation, int newFounded){
    name = newName;
    founded = newFounded;
    population = newPopulation;
}


int District::getPopulation(void){
    return population;
}

string District::getName(void){
    return name;
}

string District::toString(void){
    string theString;
    theString += "\n------Displaying District------\nName : " + this->getName() + "\nPopulation : " + to_string(this->getPopulation());
    return theString;
}

void District::displaySchools(void){
    
    cout << "Entering display schools" << endl;
    cout << "The number of schools is : " << to_string(this->schools.size()) << endl;
    for(int i = 0; i < this->schools.size(); i++){
       cout << this->schools[i].toString() << endl;
    }

}

vector<School> District::getSchools(){
    return schools;
}

void District::addSchool(School newSchool){
    schools.push_back(newSchool);
}
