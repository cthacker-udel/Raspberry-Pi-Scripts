using namespace std;
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <iostream>
#include "School.hpp"

class District{
    
    string name;
    int founded;
    int population;
    vector<School> schools;

    public:

        District();

        District(string);

        District(string,int);

        District(string,int,int);

        string getName(void);

        int getFounded(void);

        int getPopulation(void);

        string toString(void);

        void addSchool(School);

        void displaySchools(void);

        vector<School> getSchools();
};
