#include "project.h"

library *theLibrary = NULL;

library* getLibrary(){
    return theLibrary;
}

void setBooks(book *theBooks){
    theLibrary->books = theBooks;
}

library *createLibrary(){

    theLibrary = (library *)malloc(sizeof(library));
    return theLibrary;

}

