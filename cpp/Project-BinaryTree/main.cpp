#include "Node.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

/// @brief Prints the menu which the users enters CLI commands to run
void printMenu()
{
    cout << "-=-=-=MENU-=-=-=\n1)Insert Node\n2)Print pre-order\n3)Print post-order\n4)Print in-order\n5)Exit program" << endl;
}

/// @brief Prints prompt for choosing the number of the node to insert
void printNumChoiceMenu()
{

    cout << "Enter number of node to insert" << endl;
}

/// @brief The main function, controls the whole program
/// @return Whether the program succeeded or not
int main()
{

    int choice;
    int numChoice;
    Node *theRoot = NULL;
    while (true)
    {

        printMenu();
        cin >> choice;
        switch (choice)
        {

        case 1:
        {

            printNumChoiceMenu();
            cin >> numChoice;
            theRoot->insertRec(numChoice, theRoot);
            break;
        }
        case 2:
        {

            break;
        }
        case 3:
        {

            break;
        }
        case 4:
        {

            break;
        }
        default:
        {

            break;
        }
        }
    }
}