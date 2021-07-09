#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include "Ingredient.hpp"
using namespace std;

class Potion{

    string effect;
    vector<Ingredient> ingredients;
    int timeRequired;

    public:

        Potion(string,vector<Ingredient>,int);

        int getTimeRequired();

        vector<Ingredient> getIngredients();        

        string getEffect();

        int total_ingredients(vector<Potion>);

        int count_rare_ingredients(vector<Potion>);

        vector<string> get_ingredients(vector<Potion>);

        int get_brewing_time(vector<Potion>);

        float brew_time_per_ingredient(vector<Potion>);

        string get_rarest_potion(vector<Potion>);





};