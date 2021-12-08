#include "Store.hpp"

Store *theStore = NULL;

int main(void){

    if(theStore == NULL){
        system("./add_store_title.sh");
        string storeName;
        cout << "Enter the name of the store" << endl;
        cin >> storeName;
        string cmdString;
        cmdString += "./add_store_title.sh ";
        cmdString += "\"" + storeName + "\"";
        char *newCmdString = (char *)malloc(sizeof(char) * cmdString.length());
        for(int i = 0; i < cmdString.length(); i++){
            newCmdString[i] = cmdString.at(i);
        }
        newCmdString[cmdString.length()-1] = '\0';
        system(newCmdString);
    }




}