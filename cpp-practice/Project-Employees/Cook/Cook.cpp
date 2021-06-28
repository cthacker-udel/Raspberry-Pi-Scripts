#include "Cook.hpp"

Cook::Cook(){

    name = "Charlie";
    age = 20;
    numberOfRecipes = 20;

}

Cook::Cook(string newName, int newAge, int newNumberOfRecipes){

    name = newName;
    age = newAge;
    numberOfRecipes = newNumberOfRecipes;

}

Cook::~Cook(){

    delete &name;
    delete &age;
    delete &numberOfRecipes;
    delete this;

}


int Cook::getAge(){

    return age;

}

string Cook::getName(){

    return name;

}


int Cook::getNumberOfRecipes(){

    return numberOfRecipes;

}

