#include <string>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Costume{

    string label;
    int price;
    char size;

    public:

        Costume(string,int,char);

        int count_costumes(vector<Costume>);

        int total_price(vector<Costume>);

        int count_sizes(vector<Costume>);

        int max_price(vector<Costume>);

        string most_expensive_costume(vector<Costume>);

        string find_last_medium(vector<Costume>);

        string find_first_small(vector<Costume>);




};