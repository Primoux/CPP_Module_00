#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _array[8];
	public:
		int max;
		int index;
		int current;
		PhoneBook();
		~PhoneBook();
		void addContact(Contact contact);
		int printPhoneBook();
		int printPhoneBook(int index);
		int getOlderContact();
	};

#endif // !PHONEBOOK_HPP