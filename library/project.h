#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct eachBook{

    int ISBN;
    char *name;
    int pages;
    int chapters;
    char *author;
    int fiveStarReviews;
    int fourStarReviews;
    int threeStarReviews;
    int twoStarReviews;
    int oneStarReviews;
    struct eachBook *next;

}book;

typedef struct theLibrary{

    char *name;
    int founded;
    char *founder;
    int numBooks;
    book *books;

}library;

book *getHead();

library* getLibrary();

void setBooks(book *);

library *createLibrary();

void setLibraryName(char *name);

void setLibraryFounded(int);

void setLibraryFounder(char *);

void printMenu();

int getNumBooks(void);

book *createBook();

void addBook(book *);

void addISBN(book *);

void addName(book *);

void addPages(book *);

void addChapters(book *);

void addAuthor(book *);

void addFiveStarReview(book *);

void addFourStarReview(book *);

void addThreeStarReview(book *);

void addTwoStarReview(book *);

void addOneStarReview(book *);

void sortByISBNAscending();

void sortByISBNDescending();

void sortByNameAscending();

void sortByNameDescending();

void sortByPagesAscending();

void sortByPagesDescending();

void sortByChaptersAscending();

void sortByChaptersDescending();

void sortByAuthorAscending();

void sortByAuthorDescending();

void sortByFiveStarReviewsAscending();

void sortByFiveStarReviewsDescending();

void sortByFourStarReviewsAscending();

void sortByFourStarReviewsDescending();

void sortByThreeStarReviewsAscending();

void sortByThreeStarReviewsDescending();

void sortByTwoStarReivewsAscending();

void sortByTwoStarReivewsDescending();

void sortByOneStarReviewsAscending();

void sortByOneStarReviewsDescending();