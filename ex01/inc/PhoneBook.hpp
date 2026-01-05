#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "phonebook.h"

class PhoneBook
{
  private:
	Contact _array[MAX_CONTACT];
	int 	max;
	int 	current;

  public:
	PhoneBook();
	~PhoneBook();
	void addContact(Contact contact);
	int printPhoneBook();
	int printPhoneBook(int index);
};

#endif // !PHONEBOOK_HPP