#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Book{

    string authorFirst;
    string authorLast;
    int yearReleased;
    int monthReleased;
    int dayReleased;
    int id;

    public:

        Book(string,string,int,int,int);

        string getAuthorFirstName();

        string getAuthorLastName();

        int getYearReleased();

        int getMonthReleased();
        
        int getDayReleased();



};