#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

std::vector<Contact> contacts;

void addContact() {
    Contact newContact;
    std::cout << "Enter name: ";
    std::getline(std::cin, newContact.name);
    std::cout << "Enter phone: ";
    std::getline(std::cin, newContact.phone);
    std::cout << "Enter email: ";
    std::getline(std::cin, newContact.email);
    contacts.push_back(newContact);
    std::cout << "Contact added successfully!" << std::endl;
}

void updateContact() {
    std::string searchName;
    std::cout << "Enter the name of the contact to update: ";
    std::getline(std::cin, searchName);

    for (auto& contact : contacts) {
        if (contact.name == searchName) {
            std::cout << "Enter new name: ";
            std::getline(std::cin, contact.name);
            std::cout << "Enter new phone: ";
            std::getline(std::cin, contact.phone);
            std::cout << "Enter new email: ";
            std::getline(std::cin, contact.email);
            std::cout << "Contact updated successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Contact not found." << std::endl;
}

void searchContact() {
    std::string searchName;
    std::cout << "Enter the name to search: ";
    std::getline(std::cin, searchName);

    for (const auto& contact : contacts) {
        if (contact.name == searchName) {
            std::cout << "Name: " << contact.name << std::endl;
            std::cout << "Phone: " << contact.phone << std::endl;
            std::cout << "Email: " << contact.email << std::endl;
            return;
        }
    }

    std::cout << "Contact not found." << std::endl;
}

int main() {
    int choice;
    do {
        std::cout << "Address Book Menu:" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Update Contact" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                updateContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}