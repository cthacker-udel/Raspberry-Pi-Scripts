class Book{

    string name;
    int pages;
    int chapters;
    int rating; // 1-5
    int yearIssued;
    int monthIssued;
    int dayIssued;
    int isbn;

    public:

        Book(string);

        Book(string,int,int,int);

        string getName();

        int getPages();

        int getChapters();

        int getRating();

        int getYearIssued();

        int getMonthIssued();

        int getDayIssued();

        void setPages(int);

        void setChapters(int);

        void setRating(int);

        void setYearIssued(int);

        void setMonthIssued(int);

        void setDayIssued(int);


}