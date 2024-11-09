
#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;
        int     filled;
        std::string check_text_len(const std::string &str);
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact(Contact contact);
        void display_contacts();
        void display_one_contact(int index);
};