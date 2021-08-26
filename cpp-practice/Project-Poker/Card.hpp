#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Card{

    string suit;
    string rank;
    int numRank;

    public:

        Card(string,string,int);

        string getSuit();

        string getRank();

        int getNumRank();

};