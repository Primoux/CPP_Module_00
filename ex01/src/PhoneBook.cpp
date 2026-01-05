/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:39:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/05 17:26:24 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "phonebook.h"
#include <iostream>

PhoneBook::PhoneBook() : max(MAX_CONTACT - 1), current(0)
{
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::printPhoneBook()
{
	if (this->current == 0)
	{
		std::cout << "No contact inside the phone book\n" << std::endl;
		return (1);
	}
	std::cout << "\n┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i <= this->max; ++i)
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
		std::cout << "           CONTACT #" << index + 1 << std::endl;
		std::cout << "════════════════════════════════════════" << std::endl;
		this->_array[index].printContactFull();
	}
	else
	{
		std::cout << "        NO CONTACT #" << index + 1 << std::endl;
	}
	std::cout << "════════════════════════════════════════\n" << std::endl;
	return (0);
}

void PhoneBook::addContact(Contact contact)
{
	this->_array[this->current++ % MAX_CONTACT] = contact;
}
