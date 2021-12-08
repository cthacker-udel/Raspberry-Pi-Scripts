#include "Pitcher.hpp"
#include <stdlib.h>

class PitcherTeam{

    Pitcher *first;
    Pitcher *last;
    string teamName;

    public:

        PitcherTeam();

        PitcherTeam(string);

        Pitcher *addToTeam(Pitcher *);

        void displayTeam();


};