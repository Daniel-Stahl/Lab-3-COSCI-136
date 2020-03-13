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
    streetNumber = newStreetNumber; streetName = newStreetName; city = newCity; state = newState; zipcode = newZipcode;
};

string Address::GetStreetNum() { return streetNumber; }
string Address::GetStreetName() { return streetName; }
string Address::GetCity() { return city; }
string Address::GetState() { return state; }
string Address::GetZipcode() { return zipcode; }



