#include <string>
#include <iostream>
using namespace std;


class User{

    string firstName;
    int birthYear;
    int birthMonth;
    int birthDay;
    string lastName;
    friend class Rent;

    public:

        User(string,string,int,int,int);

        User();

};
