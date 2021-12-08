#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class FootballPlayer{

    string name;
    int age;
    int yardsThrown;
    int interceptionsThrown;
    int completions;
    int attmepts;
    int runYardsRan;

    public:

        FootballPlayer();

        FootballPlayer(string);

        FootballPlayer(string,int);

        ~FootballPlayer();

        void setAge(int);

        int getAge();

        string getName();

        void setName(string);

        int getYardsThrown();

        void setYardsThrown(int);

        int getInterceptionsThrown();

        void setInterceptionsThrown(int);

        int getCompletions();

        void setCompletions(int);

        int getAttempts();

        void setAttempts(int);

        int getRunYards();

        void setRunYards(int);
};