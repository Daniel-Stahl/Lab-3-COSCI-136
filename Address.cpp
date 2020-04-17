//
//  Address.cpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/9/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//

#include "Address.hpp"

using namespace std;

Address::Address(){};
Address::Address(string newStreetNumber, string newStreetName, string newCity, string newState, string newZipcode) {
    SetAddress(newStreetNumber, newStreetName, newCity, newState, newZipcode);
};

string Address::GetStreetNum() const { return streetNumber; }
string Address::GetStreetName() const { return streetName; }
string Address::GetCity() const { return city; }
string Address::GetState() const { return state; }
string Address::GetZipcode() const { return zipcode; }

void Address::SetAddress(string newStreetNumber, string newStreetName, string newCity, string newState, string newZipcode) {
    streetNumber = newStreetNumber; streetName = newStreetName; city = newCity; state = newState; zipcode = newZipcode;
}

string Address::FormatToString() {
    string formatToString = GetStreetNum() + " " + GetStreetName() + " " + GetCity() + ", " + GetState() + " " + GetZipcode();
    return formatToString;
}



