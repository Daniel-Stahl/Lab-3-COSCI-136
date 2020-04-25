#include "Address.hpp"
#include <iostream>

using namespace std;

class Contact {
public:
    Contact();
    Contact(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber);
    string FormatPhoneNumber(string number) const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetPhoneNumber() const;
    string GetContact() const;
    void SetContact(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber);
    void Print();
    
private:
    string firstName;
    string lastName;
    string phoneNumber;
    Address address;
};
