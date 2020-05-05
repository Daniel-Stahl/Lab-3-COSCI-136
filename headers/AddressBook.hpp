#include <string>
#include <fstream>
#include <iostream>
#include <new>
#include "Record.hpp"

using namespace std;

class AddressBook {
private:
    Record* head;

public:
    void LoadData();
    bool SearchContacts();
    Record*& SearchContacts(Record* node, bool& foundContact);
    void AddContact();
    void DeleteContact();
    void ExportContacts();
    void MakeSearchUpper(string& changeString);
    void MakeUppercase(string& changeStringA, string& changeStringB, string& changeStringC, string& changeStringD, string& changeStringE);
    ~AddressBook();
    void EmptyList();
};
