#include "Student.hpp"


Student::Student(){
    name = "Charles Barkley";
    age = 90;
    height = 60.0;
}


Student::Student(string newName, int newAge){
    name = newName;
    age = newAge;
}

Student::Student(string newName, int newAge, double newHeight){
    name = newName;
    age = newAge;
    height = newHeight;
}


int Student::getAge(){
    return age;
}


string Student::getName(){
    return name;
}

double Student::getHeight(){
    return height;
}

string Student::toString(){
    string theResult;

    theResult += this->name + " is " + to_string(this->age) + " years old ";

    return theResult;
}
