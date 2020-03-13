//
//  Address.hpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/9/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//
#include <string>

using namespace std;

class Address {
public:
    Address();
    Address(string newStreetNumber, string newStreetName, string newCity, string newState, string newZipcode);
    string GetStreetNum();
    string GetStreetName();
    string GetCity();
    string GetState();
    string GetZipcode();

private:
    string streetNumber;
    string streetName;
    string city;
    string state;
    string zipcode;
};
