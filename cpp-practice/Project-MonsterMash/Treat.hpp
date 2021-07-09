#include <cmath>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Treat{

    string name;
    bool chocolate;
    int calories;
    int quantity;

    public:

        Treat(string,bool,int,int);

        int eat_candy(vector<Treat>);

        float find_most_calorific_ratio(vector<Treat>);

        string find_most_calorific(vector<Treat>);

        int count_chocolates(vector<Treat>);

        int get_choco_quantity(vector<Treat>);

};