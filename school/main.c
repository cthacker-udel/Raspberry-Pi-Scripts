#include "project.h"

int main(){

    int choice;
    int chosenId;
    int foundIndex;
    school *newSchool = NULL;
    while(1){

        do{
            printMenu();
        }while(scanf("%d",&choice) != 1);
        switch(choice){

            case 1:
                if(newSchool == NULL){
                    printf("\nYou must create a school first to add a student to the school\n");
                }
                else{
                    Student *createdStudent = createStudent();
                    addStudent(newSchool,createdStudent);
                }
                break;
            
            case 2:
                if(newSchool == NULL){
                    printf("\nAttempting to display a school that is null\n");
                }
                else{
                    displaySchool(newSchool);
                }
                break;
            case 3:
                do{
                    printf("\nEnter an ID of the student to delete\n");
                }while(scanf("%d",&chosenId) != 1);
                deleteStudent(chosenId);
                break;
            case 4:
                do{
                    printf("\nEnter an ID of the student to find the index of\n");
                }while(scanf("%d",&chosenId) != 1);
                foundIndex = findStudent(chosenId);
                if(foundIndex == -1){
                    printf("\nThe student was not found in the list\n");
                }
                else{
                    printf("\nThe student is located at index %d in the list\n",foundIndex);
                }
                break;
            case 5:
                newSchool = createSchool();
                break;
            default:
                printf("\n--Exiting program--\n");
                return 0;

        }


    }


}