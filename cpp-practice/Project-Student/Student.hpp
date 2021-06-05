using namespace std;
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

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


