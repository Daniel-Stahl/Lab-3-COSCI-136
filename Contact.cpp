//
//  Contact.cpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/10/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//

#include "Contact.hpp"

#include <iostream>

using namespace std;

Contact::Contact(){};
Contact::Contact(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber) {
    firstName = newFirstName; lastName = newLastName; address = newAddress; phoneNumber = newPhoneNumber;
};

string Contact::GetLastName() { return lastName; };
string Contact::GetPhoneNumber() { return phoneNumber; };

void Contact::Print() {
    //Address address;
    cout << "Name: " << firstName << " " << lastName << "\n" << "Adddress: " << address.GetStreetNum() << " " << address.GetStreetName() << " " << address.GetCity() << ", " << address.GetState() << " " << address.GetZipcode() << "\n";
}
