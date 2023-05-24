#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Ingredient{

    string name;
    bool rare;

    public:

        Ingredient(string,bool);

        bool isRare();

        string getName();


};