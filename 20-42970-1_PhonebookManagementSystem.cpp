#include <bits/stdc++.h>
using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

void addContact(const string& fileName, const Contact& contact) {
    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    file << contact.name << "," << contact.phoneNumber << endl;
    file.close();
}

void displayContacts(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    cout << endl << "Contacts:" << endl;
    cout << setw(20) << left << "Name" << setw(15) << "Phone Number" << endl;
    cout << "---------------------------------------" << endl;

    string line;
    while (getline(file, line)) {
        size_t pos = line.find(",");
        string name = line.substr(0, pos);
        string phoneNumber = line.substr(pos + 1);
        cout << setw(20) << left << name << setw(15) << phoneNumber << endl;
    }
    file.close();
}

void searchContact(const string& fileName, const string& name) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos = line.find(",");
        string contactName = line.substr(0, pos);
        string phoneNumber = line.substr(pos + 1);
        if (contactName == name) {
            cout << endl << "Contact found:" << endl;
            cout << "Name: " << contactName << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found." << endl;
    }

    file.close();
}

int main() {
    string fileName = "phonebook.txt";
    int choice;
    Contact contact;

    while (true) {
        cout << endl << "Phonebook Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << endl << "Enter name: ";
                getline(cin, contact.name);
                cout << "Enter phone number: ";
                getline(cin, contact.phoneNumber);
                addContact(fileName, contact);
                break;
            case 2:
                displayContacts(fileName);
                break;
            case 3:
                cin.ignore();
                cout << endl  << "Enter name to search: ";
                getline(cin, contact.name);
                searchContact(fileName, contact.name);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
