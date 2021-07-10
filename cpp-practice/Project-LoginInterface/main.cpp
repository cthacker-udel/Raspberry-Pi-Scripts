#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(void){

    string userName;
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
    for(int i = 0; i < commandString.length(); i++){
        *(arr+i) = commandString.at(i);
    }
    printf("The string is : %s",arr);
    system(arr);
   return 0;

}