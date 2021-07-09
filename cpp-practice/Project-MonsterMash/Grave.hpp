#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Grave{

    string name;
    string message;

    public:

        Grave(string,string);

        int count_grave_all(vector<Grave>);

        int count_grave_characters(vector<Grave>);

        int estimate_grave_cost(vector<Grave>);

        int count_shouters(vector<Grave>);


};