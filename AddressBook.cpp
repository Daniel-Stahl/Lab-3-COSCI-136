//
//  AddressBook.cpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/9/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//

// Check for heap

#include "AddressBook.hpp"
#include <fstream>
#include <iostream>
#include <array>
#include <new>

Record* testRecord;

void AddressBook::LoadData() {
    ifstream inFile;
    string firstName;
    string lastName;
    string phoneNumber;
    string streetNumber;
    string streetName;
    string city;
    string state;
    string zipcode;
    Record* node;
    
    inFile.open("/Users/stahl/Desktop/Pierce College/COSCI 136/LAB_3_STAHL_DANIEL/data.txt");
    
    if (!inFile) {
        cout << "File doesn't exist" << endl;
        exit(1);
    } else {
        cout << "File loaded" << endl;
    }
    
    inFile >> firstName >> lastName >> streetNumber >> streetName >> city >> state >> zipcode >> phoneNumber;
    MakeUppercase(firstName, lastName, streetName, city, state);
    
    head = new Record;
    head->contact = Contact(firstName, lastName, Address(streetNumber, streetName, city, state, zipcode), phoneNumber);
    node = head;
    head->next = nullptr;
    
    while (!inFile.eof()) {
        node->next = new (std::nothrow) Record;
        
        if (!node) {
            cout << "Cant allocate memory\n";
        } else {
            node = node->next;
            inFile >> firstName >> lastName >> streetNumber >> streetName >> city >> state >> zipcode >> phoneNumber;
            MakeUppercase(firstName, lastName, streetName, city, state);
            node->contact = Contact(firstName, lastName, Address(streetNumber, streetName, city, state, zipcode), phoneNumber);
            node->next = nullptr;
        }
    }
}

bool AddressBook::SearchContacts() {
    string searchContact;
    char searchAgain;
    bool exitSearch = false;
    
    do {
        cout << "Search by last name or phone number: ";
        cin >> searchContact;
        
        // Function to make user input lowercase
        
        Record *node = head;
        Record *prev = head;
        
        while (node != nullptr && !exitSearch) {
            if (node->contact.GetLastName() == searchContact || node->contact.GetPhoneNumber() == searchContact) {
                node->contact.Print();
                exitSearch = true;
            } else {
                prev = node;
                node = node->next;
                exitSearch = false;
            }
        }
        
        if (node == prev) {
            testRecord = nullptr;
        } else {
            testRecord = prev;
        }
        
        if (node != nullptr) {
            cout << "Found contact\n";
            cout << "Search again (Y/N)? ";
            cin >> searchAgain;
        } else {
            cout << "Contact not found\n";
            cout << "Search again (Y/N)? ";
            cin >> searchAgain;
        }
        
        searchAgain = toupper(searchAgain);
        
        if (searchAgain == 'Y') {
            exitSearch = false;
        }
        
    } while (searchAgain == 'Y');
    
    return exitSearch;
}

void AddressBook::AddContact() {
    Record* newHead;
    char userChoice;
    string firstName, lastName, streetNumber, streetName, city, state, zipcode, phoneNumber;
    
    do {
        newHead = new (std::nothrow) Record;
        
        if (!newHead) {
            cout << "No more space to allocate memory\n";
        } else {
        
            cout << "First Name: ";
            cin >> firstName;
            
            cout << "Last Name: ";
            cin >> lastName;
            
            cout << "Street Number: ";
            cin >> streetNumber;
            
            cout << "Street Name: ";
            cin >> streetName;
            
            cout << "City: ";
            cin >> city;
            
            cout << "State: ";
            cin >> state;
            
            cout << "Zipcode: ";
            cin >> zipcode;
            
            cout << "Phone Number: ";
            cin >> phoneNumber;
            
            MakeUppercase(firstName, lastName, streetName, city, state);
            newHead->contact = Contact(firstName, lastName, Address(streetNumber, streetName, city, state, zipcode), phoneNumber);
            newHead->next = head;
            
            cout << "Do you want to add another contact?\n";
            cin >> userChoice;
            // Check if user choice is valid
        }
    } while (userChoice != 'n' || userChoice != 'N');
}

// Delete contact
void AddressBook::DeleteContact() {
    Record* oldHead = head;
    bool foundContact = false;
    char deleteAnother;
    
    do {
        foundContact = SearchContacts();
        
        if (foundContact) {
            if (!testRecord) {
                //Delete Head
                oldHead->contact.Print();
                head = oldHead->next;
                delete oldHead;
            } else {
                testRecord->next = testRecord->next->next;
                delete testRecord->next;
            }
            
            cout << "Want to delete another (Y/N)? ";
            cin >> deleteAnother;
        }
    } while (deleteAnother == 'Y');
}

void AddressBook::MakeUppercase(string& changeStringA, string& changeStringB, string& changeStringC, string& changeStringD, string& changeStringE) {
    string arrayOfStrings[5] = {changeStringA, changeStringB, changeStringC, changeStringD, changeStringE};
    int count = 0;
    
    while (count < 5) {
        unsigned stringSize = arrayOfStrings[count].size();
        
        for (int x = 0; x < stringSize; x++) {
            arrayOfStrings[count][x] = toupper(arrayOfStrings[count][x]);
        }
    
        count++;
    }
    
    changeStringA = arrayOfStrings[0];
    changeStringB = arrayOfStrings[1];
    changeStringC = arrayOfStrings[2];
    changeStringD = arrayOfStrings[3];
    changeStringE = arrayOfStrings[4];
}
