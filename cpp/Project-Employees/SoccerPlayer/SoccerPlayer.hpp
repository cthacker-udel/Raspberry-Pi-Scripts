#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class SoccerPlayer{

    string name;
    int age;
    int goals;
    int shotsAtt;
    int yellowCards;
    int redCards;
    int passComplete;
    int passAtt;

    public:

        SoccerPlayer();

        SoccerPlayer(string);

        ~SoccerPlayer();

        string getName();

        int getAge();

        void setAge(int);

        int getGoals();

        void setGoals(int);

        int getShotsAtt();

        void setShotsAtt(int);

        int getYellowCards();

        void setYellowCards(int);

        int getRedCards();

        void setRedCards(int);

        int getPassComplete();

        void setPassComplete(int);

        int getPassAtt();

        void setPassAtt(int);


};