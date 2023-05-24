#include "Class.hpp"
#include <iostream>
using namespace std;

Class::Class(string newName,int newSection){
    name = newName;
    section = newSection;
}

void Class::addStudent(Student newStudent){
    students.push_back(newStudent);
}

void Class::addStudents(int x){
    string studentName;
    int studentAge;
    double studentHeight;
    for(int i = 0; i < x; i++){
       cout << "Enter the students name\n";
       cin >> studentName;
       cout << "Enter the students age\n";
       cin >> studentAge;
       cout << "Enter the students height\n";
       cin >> studentHeight;
       Student newStudent(studentName,studentAge,studentHeight);
       addStudent(newStudent);
    }
} 

string Class::getName(){
    return name;
}

int Class::getSection(){
    return section;
}

vector<Student> Class::getStudents(){
    return students;
}

