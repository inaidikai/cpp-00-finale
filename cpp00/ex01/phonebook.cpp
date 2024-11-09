
#include "PhoneBook.hpp"
#include <iomanip> // setw

PhoneBook::PhoneBook(): index(0), filled(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact(Contact contact)
{
    this->contacts[index] = contact;
    index = (index + 1) % 8;
    if (filled < 8)
        filled++;
}

void PhoneBook::display_contacts()
{
    std::cout   << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "\n";
    for(int i = 0; i < filled; ++i)
    {
        std::cout   << std::setw(10) << i + 1 << "|"
                    << std::setw(10) << check_text_len(contacts[i].get_f_name()) << "|"
                    << std::setw(10) << check_text_len(contacts[i].get_l_name()) << "|"
                    << std::setw(10) << check_text_len(contacts[i].get_n_name()) << "\n";
    }
}

std::string PhoneBook::check_text_len(const std::string &str)
{
    if(str.length() > 10)
        return str.substr(0,9) + ".";
    return str;
}

void PhoneBook::display_one_contact(int index)
{
    if(index < 1 || index > filled)
    {
        std::cout << "\033[31mInvalid index\033[0m!" << "\n";
        return ;
    }
    Contact &con = contacts[index - 1];
        std::cout   << "First Name: " << con.get_f_name() << "\n"
                    << "Last Name: " << con.get_l_name() << "\n"
                    << "Nickname: " << con.get_n_name() << "\n"
                    << "Phone Number: " << con.get_phone() << "\n"
                    << "Darkest Secret: " << con.get_secret() << "\n";
}