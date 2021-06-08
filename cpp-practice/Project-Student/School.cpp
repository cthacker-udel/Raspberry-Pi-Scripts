#include "School.hpp"
#include <iostream>
using namespace std;

School::School(string newName){
    name = newName;
}

School::School(string newName,int newEnrolled){
    name = newName;
    enrolled = newEnrolled;
}

School::School(string newName, int newEnrolled, int newFounded){
    name = newName;
    enrolled = newEnrolled;
    founded = newFounded;
}

string School::getName(){
    return name;
}

int School::getEnrolled(){
    return enrolled;
}

int School::getFounded(){
    return founded;
}

vector<Class> School::getClasses(){
    return classes;
}

void School::addClass(Class newClass){
    classes.push_back(newClass);
}

void School::addClasses(int x){
    string className;
    int classSection;
    for(int i = 0; i < x; i++){
        cout << "Enter the class name\n";
        cin >> className;
        cout << "Enter the section number";
        cin >> classSection;
        Class newClass(className,classSection);
        addClass(newClass);
    }
}

string School::toString(void){
    string result = "";
    result += this->name + " has a total of " + to_string(this->classes.size()) + " classes ";
    return result;
}
