//
//  Contact.hpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/10/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//
#include "Address.hpp"

using namespace std;

class Contact {
public:
    Address address;
    Contact();
    Contact(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber);
    string FormatPhoneNumber(string number);
    string GetFirstName() const;
    string GetLastName() const;
    string GetPhoneNumber() const;
    void SetContact(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber);
    void Print();
    
private:
    string firstName;
    string lastName;
    string phoneNumber;
    
};
