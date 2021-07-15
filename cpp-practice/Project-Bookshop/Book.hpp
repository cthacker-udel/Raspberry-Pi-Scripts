#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

class Book{

    string authorFirst;
    string authorLast;
    int yearReleased;
    int monthReleased;
    int dayReleased;
    int id;
    int isbn;

    public:

        Book(string,string,int,int,int);

        string getAuthorFirstName();

        string getAuthorLastName();

        int getYearReleased();

        int getMonthReleased();
        
        int getDayReleased();



};