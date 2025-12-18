#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
  private:
	Contact _array[8];
	int getOlderContact();
	int max;
	int current;

  public:
	PhoneBook();
	~PhoneBook();
	int addContact(Contact contact);
	int printPhoneBook();
	int printPhoneBook(int index);
};

#endif // !PHONEBOOK_HPP