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

vector<string> Potion::get_ingredients(vector<Potion> potions){

    bool foundIngredient = true;

    vector<string> theIngredients;
    for(int i = 0; i < potions.size(); i++){

        Potion thePotion = potions.at(i);
        vector<Ingredient> thePotionsIngredients = thePotion.ingredients;
        
        for(int j = 0; j < thePotionsIngredients.size(); j++){
            
            string ingredient_one = thePotionsIngredients.at(j).getName();
            
            for(int k = 0; k < theIngredients.size(); k++){

                string ingredient_two = theIngredients.at(k);

                if(ingredient_one.compare(ingredient_two) == 0){
                    foundIngredient = false;
                    break;
                }
                foundIngredient = true;

            }
            if(foundIngredient){
                theIngredients.push_back(ingredient_one);
            }
        }

    }
    return theIngredients;

}

int Potion::getTimeRequired(){

    return timeRequired;

}

int Potion::get_brewing_time(vector<Potion> potions){

    int totalBrewTime = 0;

    for(int i = 0; i < potions.size(); i++){

        Potion thePotion = potions.at(i);
        totalBrewTime += thePotion.getTimeRequired();

    }

    return totalBrewTime;

}

float Potion::brew_time_per_ingredient(vector<Potion> potions){

    float totalBrewingTime = get_brewing_time(potions) * 1.0;
    int totalIngredients = total_ingredients(potions);

    if(totalIngredients == 0){
        return 0.0;
    }
    else{

        return totalBrewingTime / totalIngredients;

    }

}