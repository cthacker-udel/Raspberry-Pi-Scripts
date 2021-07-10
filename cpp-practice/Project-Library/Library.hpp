#include "Book.hpp"
#include <vector>

class Library{

    vector<Book> books;
    string libraryName;
    int founded;
    double baseCost;

    public:

        Library();

        Library(string);

        int getFounded();

        double getBaseCost();

        vector<Book> getBooks();

        string getName();

        void setFounded(int);

        void setBaseCost(double);

        void setBooks(vector<Book>);

        void setName(string);

        void addBook(Book);

        void clearBooks();

};