//
//  Address.hpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/9/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//
#include <string>
#include <iostream>

using namespace std;

class Address {
public:
    Address();
    Address(string newStreetNumber, string newStreetName, string newCity, string newState, string newZipcode);
    string GetStreetNumber() const;
    string GetStreetName() const;
    string GetCity() const;
    string GetState() const;
    string GetZipcode() const;
    void SetStreetNumber(string _StreetNumber_);
    void SetStreetName(string _StreetName_);
    void SetCity(string _City_);
    void SetState(string _State_);
    void SetZipcode(string _Zipcode_);
    
private:
    string streetNumber;
    string streetName;
    string city;
    string state;
    string zipcode;
};
