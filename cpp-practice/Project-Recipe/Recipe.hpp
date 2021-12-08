#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Ingredient.hpp"
#include "Step.hpp"

class Recipe{

    vector<Ingredient> ingredients;
    vector<Step> steps;
    string recipeName;

    public:

        Recipe(string);

        vector<Ingredient> getIngredients();

        vector<Step> getSteps();

        void addIngredient(Ingredient);

        void addStep(Step);

};