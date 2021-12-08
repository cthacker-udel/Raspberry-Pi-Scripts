#include "Class.hpp"

class School{

    vector<Class> classes;
    string name;
    int founded;
    int enrolled;


    public:

        School(string);

        School(string,int);

        School(string,int,int);

        int getFounded();

        int getEnrolled();

        string getName();

        vector<Class> getClasses();

        void addClass(Class);

        string toString(void);

        void addClasses(int);

};
