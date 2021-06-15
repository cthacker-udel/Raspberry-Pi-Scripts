#include "Book.hpp"
#include <string.h>


Book::Book(string newName){

    name = newName;

}

Book::Book(string newName, int newYearIssued, int newMonthIssued, int newDayIssued){

    name = newName;
    yearIssued = newYearIssued;
    monthIssued = newMonthIssued;
    dayIssued = newDayIssued;

}

string Book::getName(){
    return name;
}

int Book::getPages(){
    return pages;
}

int Book::getChapters(){
    return chapters;
}

int Book::getRating(){
    return rating;
}

int Book::getYearIssued(){
    return yearIssued;
}

int Book::getMonthIssued(){
    return monthIssued;
}

int Book::getDayIssued(){
    return dayIssued;
}
