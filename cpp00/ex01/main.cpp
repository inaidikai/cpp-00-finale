#include <iostream>

#include "phonebook.hpp"

int main(void)
{
    phonebook phoneBook;
    std::string cmd;

    while (cmd != "EXIT")
    {
        std::cout << std::endl
                  << "Insert either ADD, SEARCH or EXIT: ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD")
            phoneBook.addNewEntry();
        else if (cmd == "SEARCH")
        {
            if (phoneBook.getNumberOfValidContacts())
            {
                phoneBook.displayAllContacts();
                phoneBook.promptAndShowEntryByIndex();
            }
            else
            {
                std::cout << std::endl
                          << "No contacts. ADD a new one." << std::endl;
            }
        }
    }
    return (0);
}
