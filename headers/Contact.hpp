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
    Contact();
    Contact(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber);
    string GetLastName();
    string GetPhoneNumber();
    void Print();
    
private:
    string firstName;
    string lastName;
    string phoneNumber;
    Address address;
    
};
