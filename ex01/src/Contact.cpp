/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:50:09 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/20 15:08:10 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber,std::string darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

std::string Contact::truncate(std::string str, size_t width)
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

void Contact::printContactRow(int index)
{
	std::cout << "|" << std::setw(10) << index + 1;
	std::cout << "|" << std::setw(10) << truncate(this->_firstName, 10);
	std::cout << "|" << std::setw(10) << truncate(this->_lastName, 10);
	std::cout << "|" << std::setw(10) << truncate(this->_nickName, 10);
	std::cout << "|" << std::endl;
}

void Contact::printContactFull()
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

Contact::Contact() : nb(0)
{
}

Contact::~Contact()
{
}
