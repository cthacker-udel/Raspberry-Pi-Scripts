#include "Potion.hpp"

Potion::Potion(string newEffect, vector<Ingredient> newIngredients, int newTimeRequired){

    effect = newEffect;
    ingredients = newIngredients;
    timeRequired = newTimeRequired;

}

int Potion::total_ingredients(vector<Potion> potions){

    int count = 0;
    for(int i = 0; i < potions.size(); i++){
        Potion thePotion = potions.at(i);
        count += thePotion.ingredients.size();
    }
    return count;

}

int Potion::count_rare_ingredients(vector<Potion> potions){

    int count = 0;
    for(int i = 0; i < potions.size(); i++){
        Potion thePotion = potions.at(i);
        vector<Ingredient> theIngredients = thePotion.ingredients;
        for(int j = 0; j < theIngredients.size(); j++){

            if(theIngredients.at(j).isRare()){
                count++;
            }

        }
    }
    return count;

}