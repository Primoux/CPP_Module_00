#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

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
	void addContact(Contact contact);
	int printPhoneBook();
	int printPhoneBook(int index);
};

#endif // !PHONEBOOK_HPP