#include "project.h"

int main(void){


    library *theLibrary = getLibrary();
    book *books = getHead();
    book *newBook;
    int choice = 0;
    while(1){

        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                newBook = createBook();
                break;
            case 2:
                addBook(newBook);
                break;
            case 3:
                addISBN(newBook);
                break;
            case 4:
                addName(newBook);
                break;
            case 5:
                addPages(newBook);
                break;
            case 6:
                addChapters(newBook);
                break;
            case 7:
                addAuthor(newBook);
                break;
            case 8:
                addFiveStarReview(newBook);
                break;
            case 9:
                addFourStarReview(newBook);
                break;
            case 10:
                addThreeStarReview(newBook);
                break;
            case 11:
                addTwoStarReview(newBook);
                break;
            case 12:
                addOneStarReview(newBook);
                break;
            case 13:
                sortByISBNAscending();
        }
        

    }

}
