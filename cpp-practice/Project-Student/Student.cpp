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


int getAge(){
    return age;
}


string getName(){
    return name;
}

double getHeight(){
    return height;
}
