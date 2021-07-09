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

float Treat::find_most_calorific_ratio(vector<Treat> treats){

    float max = 0.0;
    for(int i = 0; i < treats.size(); i++){
        Treat theTreat = treats.at(i);
        max = fmax(max,theTreat.calories / theTreat.quantity);
    }
    return max;

}