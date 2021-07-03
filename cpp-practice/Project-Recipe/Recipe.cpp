// add recipe which is a vector of a class called ingredients, and ingredient has two variables, name and quantity, and recipe also has a vector of strings called steps, which outlines how to make the recipe
#include "Recipe.hpp"

Recipe::Recipe(string newName){

    this->recipeName = newName;

}

vector<Ingredient> Recipe::getIngredients(){

    return this->ingredients;

}

vector<Step> Recipe::getSteps(){

    return this->steps;

}

void Recipe::addIngredient(Ingredient newIngredient){

    this->ingredients.push_back(newIngredient);

}

void Recipe::addStep(Step newStep){

    this->steps.push_back(newStep);

}