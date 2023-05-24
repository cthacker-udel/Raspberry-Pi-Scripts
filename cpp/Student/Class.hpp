#include "Student.hpp"
#include <vector>

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

        void addStudents(int);

};
