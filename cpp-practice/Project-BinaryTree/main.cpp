#include "Node.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

void printMenu(){

    cout << "-=-=-=MENU-=-=-=\n1)Insert Node\n2)Print pre-order\n3)Print post-order\n4)Print in-order\n5)Exit program" << endl;

}

void printNumChoiceMenu(){

    cout << "Enter number of node to insert" << endl;

}

int main(void){

    int choice;
    int numChoice;
    Node *theRoot = NULL;
    while(true){

        printMenu();
        cin >> choice;
        switch(choice){

            case 1:{

                    printNumChoiceMenu();
                    cin >> numChoice;
                    break;
            }
            case 2:{

                break;
            }
            case 3:{

                break;
            }
            case 4:{

                break;
            }
            default:{

                break;
            }

        }


    }

}