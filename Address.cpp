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
    streetNumber = newStreetName; city = newCity; state = newState; zipcode = newZipcode;
};



