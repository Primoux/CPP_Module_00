#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact array[8];
    public:
        int max;
        int index;
        int current;
        PhoneBook();
        ~PhoneBook();
        void addContact(Contact contact);
    };

#endif // !PHONEBOOK_HPP