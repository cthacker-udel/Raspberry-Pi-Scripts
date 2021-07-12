#include "Rent.cpp"
#include <string>
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;


void displayMenu(){

    cout << "\n-=-=-=MENU-=-=-=\n1)Create rental file\n2)Log Rental\n3)Check Rental\n4)Delete rental files\n5)Exit Program\n-=-=-=-=-=-=-=-=-=-=";

}


int main(void){


    while(true){

        int choice;
        displayMenu();
        cin >> choice;
        switch(choice){
            
            case 1:{
                system("./create_rental_file.sh");

                string rentType;
                int numOf;
                double rate;
                while(true){
                    cout << "What type of rental do you want to do? (day,month,year)" << endl;
                    cin >> rentType;
                    if(rentType.compare("day") == 0){
                        break;
                    }
                    if(rentType.compare("month") == 0){
                        break;
                    }
                    if(rentType.compare("year") == 0){
                        break;
                    }
                    else{
                        cout << "Enter proper values (day,month,year)" << endl;
                    }
                }

                cout << "How many " << rentType << "(s) do you want to rent for?" << endl;

                cin >> numOf;

                cout << "What is rate you want to rent per mile?(up to 2 decimal places)" << endl;

                cin >> rate;

                Rent theRent = Rent(rentType,numOf,rate);

                /*

                Rental created

                */


            }
        }
    }




}