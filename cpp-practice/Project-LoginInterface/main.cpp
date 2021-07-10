#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void printMenu(){

    cout << "\n-=-=-=-=MENU-=-=-=-=\n1)Login\n2)Add credentials\n3)Delete login records\n4)Exit program";

}


int main(void){

    while(true){

        int choice;
        printMenu();
        cin >> choice;
        string userName;
        string pass;
        switch(choice){
            
            case 1:
                {
                    string checkString;
                    cout << "Enter your username" << endl;
                    cin >> userName;
                    cout << "Enter your password" << endl;
                    cin >> pass;
                    checkString += "check_password.sh ";
                    checkString += userName;
                    checkString += " " + pass;
                    char *newStr = (char *)malloc(sizeof(char) * checkString.length());
                    for(int i = 0; i < (int)checkString.length(); i++){
                        *(newStr+i) = checkString.at(i);
                    }
                    *(newStr+checkString.length()) = '\0';
                    printf("newstr = %s",newStr);
                    system(newStr);
                    break;
                }

            case 2:
                {
                    cout << "Enter your username" << endl;
                    cin >> userName;
                    string password;
                    cout << "Enter your password" << endl;
                    cin >> password;
                    string commandString;
                    commandString += "create_script.sh ";
                    commandString += userName + " ";
                    commandString += password;
                    char *arr = (char *)malloc(sizeof(char) * commandString.length());
                    for(int i = 0; i < (int)commandString.size(); i++){
                        char theChar = commandString.at(i);
                        *(arr+i) = commandString[i];
                    }
                    *(arr+commandString.length()) = '\0';
                    system(arr);
                    break;
                }
            case 3:
                {

                    system("remove_login.sh");
                    break;


                }

            default:
                {
                    return 0;
                }
        }
    }

}