using namespace std;
#include <string>

class Student{
    string name;
    int age;
    double height;
        
    public:

        Student();

        Student(string,int,double);

        Student(string,int);

        int getAge();

        string getName();

        double getHeight();

        string toString();

};


