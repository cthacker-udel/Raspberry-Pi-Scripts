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


library getLibrary();

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

void sortByNameAscending(book *);

void sortByNameDescending(book *);

void sortByPagesAscending(book *);

void sortByPagesDescending(book *);

void sortByChaptersAscending(book *);

void sortByChaptersDescending(book *);

void sortByAuthorAscending(book *);

void sortByAuthorDescending(book *);

void sortByNumFiveStarReviewsAscending(book *);

void sortByNumFiveStarReviewsDescending(book *);

void sortByNumFourStarReviews(book *);

void sortByNumThreeStarReviews(book *);

void sortByNumTwoStarReivews(book *);

void sortByNumOneStarReviews(book *);