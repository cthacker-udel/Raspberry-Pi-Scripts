#include <iostream>
#include <string>

using namespace std;


class HockeyPlayer{

    string name;
    string dob;
    int age;
    int height;
    int weight;

    public:

        HockeyPlayer();

        HockeyPlayer(string,string,int,int,int);

        string getName();

        string getDOB();

        int getAge();

        int getHeight();

        int getWeight();

        void setName(string);

        void setDOB(string);

        void setAge(int);

        void setHeight(int);

        void setWeight(int);

        string toString();

        void prntToString();


};