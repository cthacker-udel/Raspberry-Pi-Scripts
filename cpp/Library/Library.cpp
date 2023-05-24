#include "Library.hpp"


Library::Library(){

    libraryName = "Default Library Name";

    founded = 1900;

    baseCost = 2.50;

}

Library::Library(string newName){

    libraryName = newName;

    founded = 1900;

    baseCost = 2.50;

}

int Library::getFounded(){

    return founded;

}


double Library::getBaseCost(){

    return baseCost;

}

vector<Book> Library::getBooks(){

    return books;

}


string Library::getName(){

    return libraryName;

}

void Library::setFounded(int newFounded){

    founded = newFounded;

}


void Library::setBaseCost(double newBaseCost){

    baseCost = newBaseCost;

}

void Library::setBooks(vector<Book> newBooks){

    books = newBooks;

}

void Library::clearBooks(){

    books.clear();

}


void Library::setName(string newName){

    libraryName = newName;

}

void Library::addBook(Book newBook){

    books.push_back(newBook);

}