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

string Treat::find_most_calorific(vector<Treat> treats){
    
    string mostCalorific;
    float theMax = find_most_calorific_ratio(treats);
    for(int i = 0; i < treats.size(); i++){
        Treat theTreat = treats.at(i);
        if(theTreat.calories * 1.0 / theTreat.quantity == theMax){
            return theTreat.name;
        }
    }
    return "";

}

int Treat::count_chocolates(vector<Treat> treats){

    int count = 0;
    for(int i = 0; i < treats.size(); i++){
        Treat theTreat = treats.at(i);
        if(theTreat.chocolate){
            count++;
        }
    }
    return count;

}