//
//  AddressBook.cpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/9/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//

#include "AddressBook.hpp"

AddressBook::AddressBook(){};

AddressBook::AddressBook(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber) {
    SetFirstName(newFirstName); SetLastName(newLastName); SetAddress(newAddress); SetPhoneNumber(newPhoneNumber);
};

//Getters
string AddressBook::GetFirstName() const { return firstName; };
string AddressBook::GetLastName() const { return lastName; };
Address AddressBook::GetAddress() const { return address; };
string AddressBook::GetPhoneNumber() const { return phoneNumber; };

// Setters
void AddressBook::SetFirstName(string _FirstName_) { firstName = _FirstName_; };
void AddressBook::SetLastName(string _LastName_) { lastName = _LastName_; };
void AddressBook::SetAddress(Address _Address_) { address = _Address_; };
void AddressBook::SetPhoneNumber(string _PhoneNumber_) { phoneNumber = _PhoneNumber_; };
