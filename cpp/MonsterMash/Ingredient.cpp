#include "Ingredient.hpp"

Ingredient::Ingredient(string newName, bool isRare){

    name = newName;
    rare = isRare;

}

bool Ingredient::isRare(){

    return rare;

}

string Ingredient::getName(){

    return name;

}