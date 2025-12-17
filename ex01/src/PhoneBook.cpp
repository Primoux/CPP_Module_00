/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:39:29 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/17 15:22:21 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : max(8), index(0), current(0)
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
		std::cout << "No contact inside the phone book\n";
		return (1);
	}
	std::cout << "\n┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i < this->current; i++)
	{
		this->_array[i].printContactRow(i);
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘\n" << std::endl;
	return (0);
}

int PhoneBook::printPhoneBook(int index)
{
	if (index < this->current)
	{
		std::cout << "\n════════════════════════════════════════" << std::endl;
		std::cout << "           CONTACT #" << index << std::endl;
		std::cout << "════════════════════════════════════════" << std::endl;
		this->_array[index].printContactFull();
		std::cout << "════════════════════════════════════════\n" << std::endl;
	}
	return (0);
}

void PhoneBook::addContact(Contact contact)
{
	if (this->current > this->max)
		this->index = this->getOlderContact();
	this->_array[this->index++] = contact;
	this->current++;
}
