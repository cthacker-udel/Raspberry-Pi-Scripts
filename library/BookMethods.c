//Make a linked list representing the various books in the library, and add methods to add books, search for books, sort books, remove books, print out all the books (toString) and make a clone of the library (duplicate pointer contents to new pointer) and check if the library is empty, and get the number of books in the library
#include "project.h"

book *HEAD = NULL;

int getNumBooks(void){

    int count = 0;
    book *tempHead = HEAD;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;

}

void printMenu(){

    printf("\n~-~-~-~-MENU~-~-~-~-\n1)");

}

book *createBook(){

    book *newBook = (book *)malloc(sizeof(book));
    return newBook;
}

void addBook(book *newBook){

    book *tempHead = HEAD;
    newBook->next = tempHead;
    HEAD = newBook;

}

void addISBN(book *newBook){

    int ISBN;
    do{
        printf("\nPlease enter ISBN number to apply to book\n");
    }while(scanf("%d",&ISBN));
    newBook->ISBN = ISBN;

}

void addName(book *newBook){

    char name[100];
    do{
        printf("\nPlease enter a name to give to the book\n");
    }while(scanf("%s",name));
    strcpy(newBook->name,name);

}

void addPages(book *newBook){

    int pages;
    do{
        printf("\nPlease enter the amount of pages the book has\n");
    }while(scanf("%d",&pages));
    newBook->pages = pages;

}

void addChapters(book *newBook){

    int chapters;
    do{
        printf("\nPlease enter the amount of chapters the book has\n");
    }while(scanf("%d",&chapters));
    newBook->chapters = chapters;

}

void addAuthor(book *newBook){

    char author[100];
    do{
        printf("\nPlease enter the name of the book author\n");
    }while(scanf("%s",author));
    strcpy(newBook->author,author);
}

void addFiveStarReview(book *newBook){
    newBook->fiveStarReviews++;
}

void addFourStarReview(book *newBook){
    newBook->fourStarReviews++;
}

