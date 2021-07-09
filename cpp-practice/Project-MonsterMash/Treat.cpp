#include "Treat.hpp"

Treat::Treat(string newName, bool isChocolate, int newCalories, int newQuantity){

    name = newName;
    chocolate = isChocolate;
    calories = newCalories;
    quantity = newQuantity;

}

int Treat::eat_candy(vector<Treat> treats){

    int total = 0;
    for(int i = 0; i < treats.size(); i++){
        total += treats.at(i).calories;
    }
    return total;

}

