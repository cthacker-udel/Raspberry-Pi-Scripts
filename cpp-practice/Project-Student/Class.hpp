#include "Student.hpp"

class Class{

    string name;
    int section;
    vector<Student> students;

    public:
            
        Class(string,int);

        void addStudent(Student);

        int getSection();

        string getName();

        vector<Student> getStudents();


};
