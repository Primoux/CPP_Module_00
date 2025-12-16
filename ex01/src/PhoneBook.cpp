/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:39:29 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/16 20:53:51 by enchevri         ###   ########lyon.fr   */
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
	for (int i = 0; i < this->current; i++)
	{
		;
	}
	return (0);
}

int PhoneBook::printPhoneBook(int index)
{
	if (index < this->current)
		this->_array[index].printContact();
	return (0);
}

void PhoneBook::addContact(Contact contact)
{
	if (this->current > this->max)
		this->index = this->getOlderContact();
	this->_array[this->index++] = contact;
	this->current++;
}
