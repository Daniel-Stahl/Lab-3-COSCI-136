// Lab 3 Stahl, Daniel T TH

#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include "AddressBook.hpp"

using namespace std;

void PromptMenu();


int main() {
    PromptMenu();
}

void PromptMenu() {
    AddressBook addressBook;
    int userChoice;
    
    addressBook.LoadData();
    
    do {
        cout << "Main menu: \n" << "1) Search for contact\n" << "2) Add a new contact\n" << "3) Delete contact\n" << "4) Export contacts\n" << "5) Exit program\n" << "Please select an option: ";
        cin >> userChoice;
        
        if (!cin || userChoice <= 0) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nThat is not a valid choice, please try again\n" << endl;
        } else {
            switch (userChoice) {
                case 1:
                    // Search for contact
                    addressBook.SearchContacts();
                    break;
                case 2:
                    // Add new contact
                    addressBook.AddContact();
                    break;
                case 3:
                    // Delete contact
                    addressBook.DeleteContact();
                    break;
                case 4:
                    // Export to file
                    addressBook.ExportContacts();
                    break;
            }
        }
    } while (userChoice != 5);
}
