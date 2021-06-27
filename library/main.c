#include "project.h"

int main(void){


    library *theLibrary = getLibrary();
    book *books = getHead();
    book *newBook = NULL;
    int choice = 0;
    int dupCreationCheck = 0;
    while(1){
        if(newBook){
            displayCurrBook(newBook);
        }
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(!dupCreationCheck){
                    newBook = createBook();
                    dupCreationCheck = 1;
                    break;
                }
                else{
                    printf("\nBook already created, must add it before creating another book\n");
                    break;
                }
            case 2:
                if(dupCreationCheck){
                    addBook(newBook);
                    dupCreationCheck = 0;
                    newBook = NULL;
                    break;
                }
                else{
                    printf("\nBook must be created using option 1 first, before adding the book using this option\n");
                    break;
                }
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
                break;
            case 14:
                sortByISBNDescending();
                break;
            case 15:
                sortByNameAscending();
                break;
            case 16:
                sortByNameDescending();
                break;
            case 17:
                sortByPagesAscending();
                break;
            case 18:
                sortByPagesDescending();
                break;
            case 19:
                sortByChaptersDescending();
                break;
            case 20:
                sortByChaptersAscending();
                break;
            case 21:
                sortByAuthorAscending();
                break;
            case 22:
                sortByAuthorDescending();
                break;
            case 23:
                sortByFiveStarReviewsAscending();
                break;
            case 24:
                sortByFiveStarReviewsDescending();
                break;
            case 25:
                sortByFourStarReviewsAscending();
                break;
            case 26:
                sortByFourStarReviewsDescending();
                break;
            case 27:
                sortByThreeStarReviewsAscending();
                break;
            case 28:
                sortByThreeStarReviewsDescending();
                break;
            case 29:
                sortByTwoStarReviewsAscending();
                break;
            case 30:
                sortByTwoStarReviewsDescending();
                break;
            case 31:
                sortByOneStarReviewsAscending();
                break;
            case 32:
                sortByOneStarReviewsDescending();
                break;
            case 33:
                printf("\n--==--==--The number of books in the library--==--==--\nAvailable : %d\n--==--==--==--==--==--==--==--==--==--==--==--==--=\n",getNumBooks());
            default:
                break;
        }
        

    }

}
