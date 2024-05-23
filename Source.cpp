#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Citizen {
public:
    int id;
    string name;
    string birthDate;
    string address;

    Citizen(int id, string name, string birthDate, string address) {
        this->id = id;
        this->name = name;
        this->birthDate = birthDate;
        this->address = address;
    }
};

class CivilRegistry {
private:
    vector<Citizen> citizens;
    int nextId;

public:
    CivilRegistry() {
        nextId = 1;
    }

    void addCitizen(string name, string birthDate, string address) {
        Citizen newCitizen(nextId, name, birthDate, address);
        citizens.push_back(newCitizen);
        cout << "Citizen added with ID: " << nextId << endl;
        nextId++;
    }

    void displayCitizens() {
        if (citizens.empty()) {
            cout << "No citizens in the registry." << endl;
            return;
        }
        cout << "Civil Registry Records: " << endl;
        for (const auto& citizen : citizens) {
            cout << "ID: " << citizen.id
                << ", Name: " << citizen.name
                << ", Birth Date: " << citizen.birthDate
                << ", Address: " << citizen.address << endl;
        }
    }

    void deleteCitizen(int id) {
        for (auto it = citizens.begin(); it != citizens.end(); ++it) {
            if (it->id == id) {
                cout << "Deleting Citizen: " << it->name << endl;
                citizens.erase(it);
                return;
            }
        }
        cout << "Citizen with ID " << id << " not found." << endl;
    }
};

void showMenu() {
    cout << "Civil Registry System" << endl;
    cout << "1. Add a new citizen" << endl;
    cout << "2. Display all citizens" << endl;
    cout << "3. Delete a citizen" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    CivilRegistry registry;
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, birthDate, address;
            cout << "Enter name: ";
            cin.ignore(); // To clear the newline character from the buffer
            getline(cin, name);
            cout << "Enter birth date (DD/MM/YYYY): ";
            getline(cin, birthDate);
            cout << "Enter address: ";
            getline(cin, address);
            registry.addCitizen(name, birthDate, address);
        }
        else if (choice == 2) {
            registry.displayCitizens();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID of citizen to delete: ";
            cin >> id;
            registry.deleteCitizen(id);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
