//
//  AddressBook.hpp
//  LAB_3_STAHL_DANIEL
//
//  Created by Daniel Stahl on 3/9/20.
//  Copyright © 2020 Daniel Stahl. All rights reserved.
//
#include <string>
#include "Record.hpp"

using namespace std;

class AddressBook {
public:
    Record* head;
    
    void LoadData();
    bool SearchContacts();
    void AddContact();
    void DeleteContact();
    void MakeUppercase(string& changeStringA, string& changeStringB, string& changeStringC, string& changeStringD, string& changeStringE);

};
