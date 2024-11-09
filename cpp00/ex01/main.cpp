
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>

#include "Contact.hpp"
#include "PhoneBook.hpp"

bool isPhoneNumber(const std::string& str) {
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (str[0] == '+' && i == 0)
            continue;
        if (!std::isdigit(str[i]))
            return false;
    }
    return !str.empty();
}

void addContact(PhoneBook &phoneBook) {
    std::string first_name, last_name, nick_name, darkest_secret, phone_number, check_phone;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, first_name);
    if (first_name.empty()) {
        std::cout << "First Name \033[31mcannot be empty!\033[0m" << "\n";
        return;
    }

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last_name);
    if (last_name.empty()) {
        std::cout << "Last Name \033[31mcannot be empty!\033[0m" << "\n";
        return;
    }

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nick_name);
    if (nick_name.empty()) {
        std::cout << "Nickname \033[31mcannot be empty!\033[0m" << "\n";
        return;
    }
    
    std::cout << "Enter Phone Number: ";
    while (true) {
        std::getline(std::cin, check_phone);
        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting program.\n";
            exit(0);
        }
        if (isPhoneNumber(check_phone) && check_phone.length() > 3 && check_phone.length() < 15)
        {
            phone_number = check_phone;
            break;
        } else {
            std::cout << "\033[31mInvalid input\033";
        }
    }

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkest_secret);
    if (darkest_secret.empty()) {
        std::cout << "Darkest Secret \033[31mcannot be empty!\033[0m" << "\n";
        return;
    }

    Contact newContact(first_name, last_name, nick_name, phone_number, darkest_secret);
    phoneBook.add_contact(newContact);
    std::cout << "\033[32mContact added successfully!\033[0m" << "\n";
}

int stringToInt(const std::string& str) {
    return std::atoi(str.c_str());
}


void searchContact(PhoneBook &phoneBook) {
    phoneBook.display_contacts();

    std::string input;
    std::cout << "Enter the index of the contact to display: ";
    while (true)
    {
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting program.\n";
            exit(0);
        }
        if (input.length() == 1 && std::isdigit(input[0]))
           { if (stringToInt(input) >= 1 && stringToInt(input) <= 8)
                break;}
        std::cout << "\033[31mInvalid index\033[0m. Enter a number between 1 and 8: ";
    }

    phoneBook.display_one_contact(stringToInt(input));
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Commands are: \033[34mADD\033[0m, \033[32mSEARCH\033[0m, \033[33mEXIT\033[0m." << "\n";

    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting program.\n";
            break;
        }

        if (command == "ADD") {
            addContact(phoneBook);
        } else if (command == "SEARCH") {
            searchContact(phoneBook);
        } else if (command == "EXIT") {
            std::cout << "Exiting... Goodbye! 👋" << "\n";
            break;
        } else {
            std::cout << "\033[31mInvalid command\033[0m. Please try again." << "\n";
        }
    }

    return 0;
}