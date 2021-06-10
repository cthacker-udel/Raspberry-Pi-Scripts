#include "District.hpp"

class City{

    vector<District> districts;
    string name;
    int population;

    public:

        City();

        City(string,int);

        vector<District> getDistricts();
    
        string getName();

        int getPopulation();

        void addDistrict(District);

        void setName(string);

        void setPopulation(int);

};
