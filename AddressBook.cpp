#include "AddressBook.hpp"

Record* recordRef;

void AddressBook::LoadData() {
    ifstream inFile;
    string firstName;
    string lastName;
    string phoneNumber;
    string streetNumber;
    string streetName;
    string city;
    string state;
    string zipcode;
    Record* node;
    
    inFile.open("/Users/stahl/Desktop/Pierce College/COSCI 136/LAB_3_STAHL_DANIEL/data.txt");
    
    if (!inFile) {
        cout << "File doesn't exist" << endl;
        exit(1);
    }
    
    inFile >> firstName >> lastName >> streetNumber >> streetName >> city >> state >> zipcode >> phoneNumber;
    MakeUppercase(firstName, lastName, streetName, city, state);
    
    head = new (std::nothrow) Record;
    
    if (!head) {
        cout << "Can't allocate memory\n";
    } else {
        head->contact = Contact(firstName, lastName, Address(streetNumber, streetName, city, state, zipcode), phoneNumber);
        node = head;
        head->next = nullptr;
    }
    
    while (!inFile.eof()) {
        node->next = new (std::nothrow) Record;
        
        if (!node) {
            cout << "Can't allocate memory\n";
        } else {
            node = node->next;
            inFile >> firstName >> lastName >> streetNumber >> streetName >> city >> state >> zipcode >> phoneNumber;
            MakeUppercase(firstName, lastName, streetName, city, state);
            node->contact = Contact(firstName, lastName, Address(streetNumber, streetName, city, state, zipcode), phoneNumber);
            node->next = nullptr;
        }
    }
    
    inFile.close();
}

bool AddressBook::SearchContacts() {
    string searchContact;
    char searchAgain;
    bool exitSearch = false;
    
    do {
        cout << "\nSearch by last name or phone number (type BACK to go back to main menu): ";
        cin >> searchContact;

        MakeSearchUpper(searchContact);
        
        if (searchContact != "BACK") {
            exitSearch = false;
            Record *node = head;
            Record *prev = head;
            
            while (node != nullptr && !exitSearch) {
                if (node->contact.GetLastName() == searchContact || node->contact.GetPhoneNumber() == searchContact) {
                    node->contact.Print();
                    exitSearch = true;
                } else {
                    prev = node;
                    node = node->next;
                    exitSearch = false;
                }
            }
            
            if (node == prev) {
                recordRef = nullptr;
            } else {
                recordRef = prev;
            }
            
            if (node != nullptr) {
                cout << "Found contact\n";
            } else {
                cout << "Contact not found\n";
            }
            
            cout << "Search again (Y/N)? ";
            cin >> searchAgain;
            cout << "\n";
            
            searchAgain = toupper(searchAgain);
        }
        
    } while (searchAgain == 'Y');
    
    return exitSearch;
}

Record* AddressBook::SearchContacts(Record*& node) {
    return node;
}


void AddressBook::AddContact() {
    Record* newHead;
    char userChoice;
    string firstName, lastName, streetNumber, streetName, city, state, zipcode, phoneNumber;
    
    cout << "Create contact prompt, continue? (Y/N): ";
    cin >> userChoice;
    cout << "\n";
    userChoice = toupper(userChoice);
    
    if (userChoice != 'N') {
        do {
            newHead = new (std::nothrow) Record;
            
            if (!newHead) {
                cout << "No more space to allocate memory\n";
            } else {
                cout << "First Name: ";
                cin >> firstName;
                
                cout << "Last Name: ";
                cin >> lastName;
                
                cout << "Street Number: ";
                cin >> streetNumber;
                
                cout << "Street Name: ";
                cin >> streetName;
                
                cout << "City: ";
                cin >> city;
                
                cout << "State: ";
                cin >> state;
                
                cout << "Zipcode: ";
                cin >> zipcode;
                
                cout << "Phone Number: ";
                cin >> phoneNumber;
                
                MakeUppercase(firstName, lastName, streetName, city, state);
                newHead->contact = Contact(firstName, lastName, Address(streetNumber, streetName, city, state, zipcode), phoneNumber);
                newHead->next = head;
                head = newHead;
                
                cout << "Do you want to add another contact (Y/N)?\n";
                cin >> userChoice;
                cout << "\n";
                userChoice = toupper(userChoice);
            }
        } while (userChoice == 'Y');
    }
}

// Delete contact
void AddressBook::DeleteContact() {
    Record* oldHead = head;
    Record* tempRecord;
    bool foundContact = false;
    char deleteAnother;
    
    do {
        foundContact = SearchContacts();
        
        tempRecord = SearchContacts(<#Record *&node#>)
        
        if (foundContact) {
            if (!recordRef) {
                head = oldHead->next;
                delete oldHead;
            } else {
                recordRef->next = recordRef->next->next;
                delete recordRef->next;
            }
            
            cout << "Contact deleted\n" << "Want to delete another (Y/N)? ";
            cin >> deleteAnother;
            cout << "\n";
            deleteAnother = toupper(deleteAnother);
        }
    } while (deleteAnother == 'Y');
}

void AddressBook::ExportContacts() {
    Record* exportHead = head;
    ofstream outFile;
    
    outFile.open("/Users/stahl/Desktop/Pierce College/COSCI 136/LAB_3_STAHL_DANIEL/exported_contacts.txt");
    
    if (!outFile) {
        cout << "No file exists\n";
        exit(2);
    }
    
    while (exportHead != NULL) {
        outFile << exportHead->contact.GetContact();
        exportHead = exportHead->next;
    }
    
    cout << "\nExport complete!\n" << endl;
    outFile.close();
}

void AddressBook::MakeSearchUpper(string& changeString) {
    int stringSize = changeString.size();
    int x = 0;
    
    while (stringSize > 0) {
        changeString[x] = toupper(changeString[x]);
        stringSize--;
        x++;
    }
};

void AddressBook::MakeUppercase(string& changeStringA, string& changeStringB, string& changeStringC, string& changeStringD, string& changeStringE) {
    string arrayOfStrings[5] = {changeStringA, changeStringB, changeStringC, changeStringD, changeStringE};
    int count = 0;
    
    while (count < 5) {
        unsigned stringSize = arrayOfStrings[count].size();
        
        for (int x = 0; x < stringSize; x++) {
            arrayOfStrings[count][x] = toupper(arrayOfStrings[count][x]);
        }
    
        count++;
    }
    
    changeStringA = arrayOfStrings[0];
    changeStringB = arrayOfStrings[1];
    changeStringC = arrayOfStrings[2];
    changeStringD = arrayOfStrings[3];
    changeStringE = arrayOfStrings[4];
}

AddressBook::~AddressBook() {
    EmptyList();
}

void AddressBook::EmptyList() {
    Record* oldHead = head;
    Record* newHead;
    
    while (oldHead != NULL) {
        newHead = oldHead->next;
        delete oldHead;
        oldHead = newHead;
    }
}
