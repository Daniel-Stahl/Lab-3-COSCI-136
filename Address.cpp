//
//  Address.cpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/9/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//

#include "Address.hpp"



Address::Address(){};
Address::Address(string newStreetNumber, string newStreetName, string newCity, string newState, string newZipcode) {
    SetStreetNumber(newStreetNumber); SetStreetName(newStreetName); SetCity(newCity); SetState(newState); SetZipcode(newZipcode);
};

// Getters
string Address::GetStreetNumber() const { return streetNumber; };
string Address::GetStreetName() const { return streetName; };
string Address::GetCity() const { return city; };
string Address::GetState() const { return state; };
string Address::GetZipcode() const { return zipcode; };

// Setters
void Address::SetStreetNumber(string _StreetNumber_) { streetNumber = _StreetNumber_; };
void Address::SetStreetName(string _StreetName_) { streetName = _StreetName_; };
void Address::SetCity(string _City_) { city = _City_; };
void Address::SetState(string _State_) { state = _State_; };
void Address::SetZipcode(string _Zipcode_) { zipcode = _Zipcode_; };
