//
//  AddressBook.hpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/9/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//
#include <string>
#include <iostream>
#include "Address.hpp"

using namespace std;

class AddressBook {
public:
    AddressBook();
    AddressBook(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber);
    string GetFirstName() const;
    string GetLastName() const;
    Address GetAddress() const;
    string GetPhoneNumber() const;
    void SetFirstName(string _FirstName_);
    void SetLastName(string _LastName_);
    void SetAddress(Address _Address_);
    void SetPhoneNumber(string _PhoneNumber_);
    
private:
    string firstName;
    string lastName;
    Address address;
    string phoneNumber;
};
