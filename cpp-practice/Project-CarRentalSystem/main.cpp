#include "Rent.hpp"

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
                    break;
                }
                case 2:{
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

                    cout << "Variables are : \nBirth year : " << theRent.getUser()->getBirthYear() << "\nBirth month : " << theRent.getUser()->getBirthYear() << "\nBirth day : " << theRent.getUser()->getBirthDay() << "\nManufacturer : " << theRent.getCar()->getManufacturer() << "\nModel year : " << theRent.getCar()->getYear() << "\nMiles : " << theRent.getCar()->getMiles() << endl;

                    string commandString = "./log_rental.sh ";
                    commandString += theRent.getUser()->getFirstName() + " ";
                    cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getUser()->getLastName() + " ";
                    cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getUser()->getBirthYear() + " ";
                    cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getUser()->getBirthMonth() + " ";
                    cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getUser()->getBirthDay() + " ";
                    cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getCar()->getManufacturer() + " ";
                    cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getCar()->getYear() + " ";
                    cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getCar()->getMiles();
                    cout << "The command string is : " << commandString << endl;

                    break;
                }


	      }
    }

}
