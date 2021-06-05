#include <string>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Student{
    string name;
    int age;
    double height;
        
    public:

        Student();

        Student(string,int,double);

        Student(string,int);

        int getAge();

        string getName();

        double getHeight();

        string toString();

};


