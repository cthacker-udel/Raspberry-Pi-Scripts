#include "Book.hpp"
#include <vector>

class Library{

    vector<Book> books;
    string libraryName;
    int founded;
    int baseCost;

    public:

        Library();

        Library(string);

        int getFounded();

        int getBaseCost();

        vector<Book> getBooks();

        string getName();

        void setFounded(int);

        void setBaseCost(int);

        void setBooks(vector<Book>);

        void setName(string);

        void addBook(Book);

};