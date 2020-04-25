#include "Contact.hpp"

using namespace std;

Contact::Contact(){};
Contact::Contact(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber) {
    SetContact(newFirstName, newLastName, newAddress, newPhoneNumber);
}

string Contact::GetFirstName() const { return firstName; };
string Contact::GetLastName() const { return lastName; };
string Contact::GetPhoneNumber() const { return phoneNumber; };

void Contact::SetContact(string newFirstName, string newLastName, Address newAddress, string newPhoneNumber) {
    firstName = newFirstName; lastName = newLastName; address = newAddress; phoneNumber = newPhoneNumber;
}

string Contact::GetContact() const {
    return firstName + " " + lastName + " " + address.GetStreetNum() + " " + address.GetStreetName() + " " + address.GetCity() + " " + address.GetState() + " " + address.GetZipcode() + " " + FormatPhoneNumber(phoneNumber) + "\n";
}

void Contact::Print() {
    cout << "Name: " << firstName << " " << lastName << "\n" << "Adddress: " << address.ToString() << "\n" << "Phone number: " << phoneNumber << "\n";
}

string Contact::FormatPhoneNumber(string number) const {
    number.insert(0, "(");
    number.insert(4, ")");
    number.insert(5, " ");
    number.insert(9, " ");
    
    return number;
}
