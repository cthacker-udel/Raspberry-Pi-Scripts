#include "District.cpp"


int main(void){

    District newDistrict;

    cout << newDistrict.toString() << endl;

    for(int i = 0; i < 5; i++){
        string schoolName;
        cout << "Enter the school name" << endl;
        cin >> schoolName;
        int numberOfStudents;
        cout << "Enter the number of students in the school" << endl;
        cin >> numberOfStudents;
        School newSchool(schoolName,numberOfStudents);
        cout << "The new school is : " << newSchool.getName() << " and amount of students is : " << to_string(newSchool.getEnrolled()) << endl;
        newDistrict.getSchools().push_back(newSchool); 
    }
    
    cout << "Before display schools" << endl;
    newDistrict.displaySchools();
    
    return 0;
}
