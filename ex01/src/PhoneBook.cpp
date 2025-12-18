/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:39:29 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/18 11:28:51 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "phonebook.h"

PhoneBook::PhoneBook() : max(MAX_CONTACT - 1), current(0)
{
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::getOlderContact()
{
	int	oldestIndex;
	int	oldestNb;

	oldestIndex = 0;
	oldestNb = this->_array[0].nb;
	for (int i = 1; i < this->max; i++)
	{
		if (this->_array[i].nb < oldestNb)
		{
			oldestNb = this->_array[i].nb;
			oldestIndex = i;
		}
	}
	return (oldestIndex);
}

int PhoneBook::printPhoneBook()
{
	if (this->current == 0)
	{
		std::cout << "No contact inside the phone book" << std::endl;
		return (1);
	}
	std::cout << "\n┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i <= this->max; i++)
	{
		this->_array[i].printContactRow(i);
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘\n" << std::endl;
	return (0);
}

int PhoneBook::printPhoneBook(int index)
{
	std::cout << "\n════════════════════════════════════════" << std::endl;
	if (index < this->current)
	{
		std::cout << "           CONTACT #" << index << std::endl;
		std::cout << "════════════════════════════════════════" << std::endl;
		this->_array[index].printContactFull();
	}
	else
	{
		std::cout << "        NO CONTACT #" << index << std::endl;
	}
	std::cout << "════════════════════════════════════════" << std::endl;
	return (0);
}

int PhoneBook::addContact(Contact contact)
{
	int index;
	contact.nb = current;
	if (this->current > this->max)
		index = this->getOlderContact();
	else
		index = current;
	this->_array[index] = contact;
	this->current++;
	return (index);
}
