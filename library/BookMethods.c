//Make a linked list representing the various books in the library, and add methods to add books, search for books, sort books, remove books, print out all the books (toString) and make a clone of the library (duplicate pointer contents to new pointer) and check if the library is empty, and get the number of books in the library
#include "project.h"

book *HEAD = NULL;

book *getHead(){
    return HEAD;
}

void displayCurrBook(book *theBook){

    printf("\n-=-=-=-=CURRENT BOOK-=-=-=-=\n");
    if(theBook->ISBN != 0){
        printf("ISBN : %d\n",theBook->ISBN);
    }
    if(theBook->name != 0){
        printf("Name : %s\n",theBook->name);
    }
    if(theBook->pages != 0){
        printf("Pages : %d\n",theBook->pages);
    }
    if(theBook->chapters != 0){
        printf("Chapters : %d\n",theBook->chapters);
    }
    if(theBook->author != 0){
        printf("Author : %s\n",theBook->author);
    }
    if(theBook->fiveStarReviews != 0){
        printf("Five Star Reviews : %d\n",theBook->fiveStarReviews);
    }
    if(theBook->fourStarReviews != 0){
        printf("Four Star Reviews : %d\n",theBook->fourStarReviews);
    }
    if(theBook->threeStarReviews != 0){
        printf("Three Star Reviews : %d\n",theBook->threeStarReviews);
    }
    if(theBook->twoStarReviews != 0){
        printf("Two Star Reviews : %d\n",theBook->twoStarReviews);
    }
    if(theBook->oneStarReviews != 0){
        printf("One Star Reviews : %d\n",theBook->oneStarReviews);
    }
}

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

    printf("\n~-~-~-~-MENU~-~-~-~-\n1)Create base book\n2)Add book to list\n3)Add ISBN to book\n4)Add name to book\n5)Add number of pages to book\n6)Add number of chapters to book\n7)Add author to book\n8)Add five star review to book\n9)Add four star review to book\n10)Add three star review to book\n11)Add two star review to book\n12)Add one star review to book\n13)Sort by ISBN Ascending\n14)Sort by ISBN descending\n15)Sort by book name ascending\n16)Sort by book name descending\n17)Sory by page number ascending\n18)Sort by page number descending\n19)Sort by number of chapters Ascending\n20)Sort by number of chapters Descending\n21)Sort by author name ascending\n22)Sort by author name descending\n23)Sort by number of five star reviews ascending\n24)Sort by number of five star reviews descending\n25)Sort by number of four star reviews ascending\n26)Sort by number of four star reviews descending\n27)Sort by number of three star reviews ascending\n28)Sort by number of three star reviews descending\n29)Sort by number of two star reivews ascending\n30)Sort by number of two star reviews descending\n31)Sort by number of one star reviews ascending\n32)Sort by number of one star reviews descending\n33)Exit program\n\tInput  :   ");

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
    }while(!scanf("%d",&ISBN));
    newBook->ISBN = ISBN;

}

void addName(book *newBook){

    char name[100];
    do{
        printf("\nPlease enter a name to give to the book\n");
    }while(!scanf("%s",name));
    newBook->name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(newBook->name,name);

}

void addPages(book *newBook){

    int pages;
    do{
        printf("\nPlease enter the amount of pages the book has\n");
    }while(!scanf("%d",&pages));
    newBook->pages = pages;

}

void addChapters(book *newBook){

    int chapters;
    do{
        printf("\nPlease enter the amount of chapters the book has\n");
    }while(!scanf("%d",&chapters));
    newBook->chapters = chapters;

}

void addAuthor(book *newBook){

    char author[100];
    do{
        printf("\nPlease enter the name of the book author\n");
    }while(!scanf("%s",author));
    newBook->author = (char *)malloc(sizeof(char) * strlen(author));
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

void sortByChaptersAscending(){

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


void sortByChaptersDescending(){

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

void sortByTwoStarReviewsAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->twoStarReviews > forwardNode->twoStarReviews){
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

void sortByTwoStarReviewsDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->twoStarReviews < forwardNode->twoStarReviews){
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

void sortByOneStarReviewsAscending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->oneStarReviews > forwardNode->oneStarReviews){
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

void sortByOneStarReviewsDescending(){

    int loopvar = 1;
    while(1){
        book *tempHead = HEAD;
        book *prevNode = HEAD;
        book *forwardNode;
        while(prevNode != NULL && forwardNode != NULL){
            forwardNode = prevNode->next;
            if(forwardNode != NULL && prevNode->oneStarReviews < forwardNode->oneStarReviews){
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


