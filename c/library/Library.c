#include "project.h"

library *theLibrary = NULL;

library* getLibrary(){
    return theLibrary;
}

void setBooks(book *theBooks){
    theLibrary->books = theBooks;
    book *tempHead = theLibrary->books;
    int count = 0;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    theLibrary->numBooks = count;
}

library *createLibrary(){

    theLibrary = (library *)malloc(sizeof(library));
    return theLibrary;

}

void setLibraryName(char *name){
    strcpy(theLibrary->name,name);
}

void setLibraryFounded(int newFounded){

    theLibrary->founded = newFounded;

}

void setLibraryFounder(char *founder){
    strcpy(theLibrary->founder,founder);
}

