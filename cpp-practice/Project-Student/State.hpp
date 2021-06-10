#include "City.hpp"

class State{
    
    vector<City> cities;
    string name;
    int population;
    string capital;


    public:

        State();

        State(string,int);

        void setName(string);

        void setPopulation(int);

        void setCapital(string);

        void addCity(City);

        string getName();

        int getPopulation();

        string getCapital();


};
