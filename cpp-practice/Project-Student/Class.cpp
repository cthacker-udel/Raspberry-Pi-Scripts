#include "Class.hpp"

Class::Class(string newName,int newSection){
    name = newName;
    section = newSection;
}

void Class::addStudent(Student newStudent){
    students.push_back(newStudent);
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

