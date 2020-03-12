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
#include <new>

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
        
            node->contact = Contact(firstName, lastName, Address(streetNumber, streetName, city, state, zipcode), phoneNumber);
            
            node->next = nullptr;
        }
    }
};

void AddressBook::SearchContacts(string _SearchFor_) {
    Record* node;
    node = head;
    bool exitSearch = false;
    
    while (node != nullptr && !exitSearch) {
        if (node->contact.GetLastName() == _SearchFor_ || node->contact.GetPhoneNumber() == _SearchFor_) {
            node->contact.Print();
            exitSearch = true;
        } else {
            node = node->next;
        }
    }
};

void AddressBook::PrintContact() {
    head->contact.Print();
}
