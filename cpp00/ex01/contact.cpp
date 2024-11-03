
#include <iostream>

#include "contact.hpp"

Contact::Contact(void) : _isEmpty(true)
{
}

Contact::~Contact(void)
{
}

void Contact::addSingleField(std::string id)
{
    std::string value;
    while (!value.length())
    {
        std::cout << "Insert ";
        if (id == "FIRST")
        {
            std::cout << "first name: ";
            std::getline(std::cin, value);
            this->_firstName = value;
        }
        else if (id == "LAST")
        {
            std::cout << "last name: ";
            std::getline(std::cin, value);
            this->_lastName = value;
        }
        else if (id == "NICK")
        {
            std::cout << "nickname: ";
            std::getline(std::cin, value);
            this->_nickName = value;
        }
        else if (id == "PHONE")
        {
            std::cout << "phone number: ";
            std::getline(std::cin, value);
            this->_phoneNumber = value;
        }
        else if (id == "SECRET")
        {
            std::cout << "darkest secret: ";
            std::getline(std::cin, value);
            this->_darkestSecret = value;
        }
    }
}


bool Contact::getIsEmpty(void) const
{
    return (this->_isEmpty);
}

void Contact::setIsEmptyToFalse()
{
    this->_isEmpty = false;
}


std::string Contact::getFirstName(void) const
{
    return this->_firstName;
}
std::string Contact::getLastName(void) const
{
    return this->_lastName;
}
std::string Contact::getNickName(void) const
{
    return this->_nickName;
}
std::string Contact::getPhoneNumber(void) const
{
    return this->_phoneNumber;
}
std::string Contact::getDarkestSecret(void) const
{
    return this->_darkestSecret;
}
