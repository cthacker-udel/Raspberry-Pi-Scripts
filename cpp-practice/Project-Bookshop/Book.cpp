#include "Book.hpp"

Book::Book(string newFirst, string newLast, int newYearReleased, int newMonthReleased, int newDayReleased){

    srand(time(NULL));

    this->authorFirst = newFirst;
    this->authorLast = newLast;
    this->yearReleased = newYearReleased;
    this->monthReleased = newMonthReleased;
    this->dayReleased = newDayReleased;
    this->id = rand() % rand();
    this->isbn = (rand() % 10000) + 1000;

}

string Book::getAuthorFirstName(){

    return this->authorFirst;

}

string Book::getAuthorLastName(){

    return this->authorLast;

}

int Book::getYearReleased(){

    return this->yearReleased;

}

int Book::getMonthReleased(){

    return this->monthReleased;

}

int Book::getDayReleased(){

    return this->dayReleased;

}