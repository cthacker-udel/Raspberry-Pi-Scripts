#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class LeftFielder{

    string name;
    int catches;
    int doublePlays;

    public:

        LeftFielder(string);

        LeftFielder(string,int);

        LeftFielder(string,int,int);

        string getName();

        int getCatches();

        int getDoublePlays();

        void setName(string);

        void setCatches(int);

        void setDoublePlays(int);

};