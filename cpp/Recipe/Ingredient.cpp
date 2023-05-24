#include "Ingredient.hpp"

Ingredient::Ingredient(string newName, string newQtyMeasurement, int newQuantity){

    this->name = newName;
    this->qtyMeasurement = newQtyMeasurement;
    this->quantity = newQuantity;

}

string Ingredient::getName(){

    return this->name;

}

string Ingredient::getQtyMeasurement(){

    return this->qtyMeasurement;

}

int Ingredient::getQuantity(){

    return this->quantity;

}