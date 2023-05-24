#include <string>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Cook{

    string name;
    int age;
    int numberOfRecipes;

    public:

        Cook();

        Cook(string,int,int);

        ~Cook();

        int getAge();

        string getName();

        int getNumberOfRecipes();



};