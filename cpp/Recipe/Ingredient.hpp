#include <stdlib.h>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Ingredient{

    friend class Recipe;
    string name;
    string qtyMeasurement;
    int quantity;

    public:

        Ingredient(string,string,int);

        string getName();

        string getQtyMeasurement();

        int getQuantity();


};