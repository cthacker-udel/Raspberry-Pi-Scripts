#include "User.hpp"

User::User(){

    cout << "Enter your first name" << endl;
    cin >> this->firstName;
    cout << "Enter your last name" << endl;
    cin >> this->lastName;
    cout << "Enter your birth year" << endl;
    cin >> this->birthYear;
    cout << "Enter your birth month" << endl;
    cin >> this->birthMonth;
    cout << "Enter your birth day" << endl;
    cin >> this->birthDay;

}

User::User(string newFirstName, string newLastName, int newBirthYear, int newBirthMonth, int newBirthDay){

    this->firstName = newFirstName;
    this->lastName = newLastName;
    this->birthYear = newBirthYear;
    this->birthMonth = newBirthMonth;
    this->birthDay = newBirthDay;

}

string User::getFirstName(){
    return this->firstName;
}

string User::getLastName(){
    return this->lastName;
}

int User::getBirthYear(){
    return this->birthYear;
}

int User::getBirthMonth(){
    return this->birthMonth;
}

int User::getBirthDay(){
    return this->birthDay;
}
