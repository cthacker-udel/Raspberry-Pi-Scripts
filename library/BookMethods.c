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

void addThreeStarReview(book *newBook){
    newBook->threeStarReviews++;
}

void addTwoStarReview(book *newBook){
    newBook->twoStarReviews++;
}

void addOneStarReview(book *newBook){
    newBook->oneStarReviews++;
}

void sortByISBNAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->ISBN > forwardNode->ISBN){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByISBNDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->ISBN < forwardNode->ISBN){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByNameAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && strcmp(prevNode->name,forwardNode->name) > 0){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByNameDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && strcmp(prevNode->name,forwardNode->name) < 0){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByPagesAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->pages > forwardNode->pages){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByPagesDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->pages < forwardNode->pages){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByPagesAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->chapters > forwardNode->chapters){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}


void sortByPagesDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->chapters < forwardNode->chapters){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByAuthorAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && strcmp(prevNode->author,forwardNode->author) > 0){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByAuthorDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && strcmp(prevNode->author,forwardNode->author) < 0){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByFiveStarReviewsAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->fiveStarReviews > forwardNode->fiveStarReviews){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByFiveStarReviewsDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->fiveStarReviews < forwardNode->fiveStarReviews){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByFourStarReviewsAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->fourStarReviews > forwardNode->fourStarReviews){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}


void sortByFourStarReviewsDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->fourStarReviews < forwardNode->fourStarReviews){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}

void sortByThreeStarReviewsAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->threeStarReviews > forwardNode->threeStarReviews){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}


void sortByThreeStarReviewsDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->threeStarReviews < forwardNode->threeStarReviews){
                prevNode->next = forwardNode->next;
                forwardNode->next = prevNode;
                if(prevNode == HEAD){
                    HEAD = forwardNode;
                    loopvar = 0;
                }
                else{
                    HEAD = tempHead;
                    book *temp = HEAD;
                    while(temp->next != NULL){
                        if(temp->next == prevNode){
                            temp->next = forwardNode;
                            break;
                        }
                    }
                    loopvar = 0;
                }
                break;
            }
            loopvar = 1;
            prevNode = prevNode->next;
        }
        if(loopvar){
            HEAD = tempHead;
            break;
        }
    }

}


