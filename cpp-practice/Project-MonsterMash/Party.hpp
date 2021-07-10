#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Party{

    string type;
    int werewolves;
    int vampires;
    int witches;

    public:

        Party(string,int,int,int);

        int sumGuests(Party);

        bool were_only_werewolves(Party);

        int totalFolks(Party);

        string check_party_size(Party);

        float check_party_ratio(Party);


};