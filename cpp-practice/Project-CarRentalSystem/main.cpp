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


                    string commandString = "./log_rental.sh ";
                    commandString += theRent.getUser()->getFirstName() + " ";
                    //cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getUser()->getLastName() + " ";
                    //cout << "The command string is : " << commandString << endl;
                    commandString += to_string(theRent.getUser()->getBirthYear()) + " ";
                    //cout << "The command string is : " << commandString << endl;
                    commandString += to_string(theRent.getUser()->getBirthMonth()) + " ";
                    //cout << "The command string is : " << commandString << endl;
                    commandString += to_string(theRent.getUser()->getBirthDay()) + " ";
                    //cout << "The command string is : " << commandString << endl;
                    commandString += theRent.getCar()->getManufacturer() + " ";
                    //cout << "The command string is : " << commandString << endl;
                    commandString += to_string(theRent.getCar()->getYear()) + " ";
                    //cout << "The command string is : " << commandString << endl;
                    commandString += to_string(theRent.getCar()->getMiles());
                    //cout << "The command string is : " << commandString << endl;
                    char *newCmdString = (char *)malloc(sizeof(char) * commandString.length()+1);
                    for(int i = 0; i < commandString.length(); i++){
                        *(newCmdString+i) = commandString.at(i);
                    }
                    *(newCmdString+commandString.length()+1) = '\0';
                    printf("The command string is : %s",newCmdString);
                    system(newCmdString);

                    break;
                }
				case 3:{

					string firstName;
					string lastName;
					int birthYear;
					int birthMonth;
					int birthDay;
					string carManu;
					int carYear;
					int carMiles;
					cout << "Enter first name" << endl;
					cin >> firstName;
					cout << "Enter last name" << endl;
					cin >> lastName;
					cout << "Enter birth year" << endl;
					cin >> birthYear;
					cout << "Enter birth month" << endl;
					cin >> birthMonth;
					cout << "Enter birth day" << endl;
					cin >> birthDay;
					cout << "Enter car manufacturer" << endl;
					cin >> carManu;
					cout << "Enter car model year" << endl;
					cin >> carYear;
					cout << "Enter car miles" << endl;
					cin >> carMiles;
					string searchString;
					string fullname = "[Name : " + firstName + " " + lastName + "]";
					string dob = "[Date of Birth : " + to_string(birthDay) + "/" + to_string(birthMonth) + "/" + to_string(birthYear) + "]";
					string carDetails = "[Manufacturer : " + carManu + " | Year : " + to_string(carYear) + " | Miles : " + to_string(carMiles) + "]";
					searchString = fullname + " " + dob + " " + carDetails;
                    searchString = "./search_rental.sh " + searchString;
                    char *newSrchStr = (char *)malloc(sizeof(char) * searchString.length()+1);
                    for(int i = 0; i < searchString.length(); i++){
                        *(newSrchStr+i) = searchString.at(i);
                    }     
                    *(newSrchStr+searchString.length()+1) = '\0';
                    system(newSrchStr);

				}



	      }
    }

}
