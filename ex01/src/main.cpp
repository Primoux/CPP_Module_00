/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:54 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/20 15:14:13 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "phonebook.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

void	clear(void)
{
	std::system("clear");
}

void	search(PhoneBook phoneBook)
{
	clear();
	if (phoneBook.printPhoneBook() == 1)
		return ;
	std::cout << "Enter the index of the contact [1]-[" << MAX_CONTACT << "]" << std::endl;
	std::string index;
	std::getline(std::cin, index);
	clear();
	std::stringstream ss(index);
	int	i;
	if (index.empty() || (ss >> i).fail() || !ss.eof())
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (i < 1 || i > 8)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	phoneBook.printPhoneBook(i - 1);
}

int	getInput(std::string prompt, std::string &str)
{
	std::cout << prompt;
	std::getline(std::cin, str);
	if (str.empty())
	{
		clear();
		std::cout << "Error\nThe string is empty\n" << std::endl;
		return (1);
	}
	clear();
	return (0);
}

int	add(PhoneBook &phoneBook)
{
	clear();
	std::string firstName;
	if (getInput("Enter your first name\n", firstName) == 1)
		return (1);
	std::string lastName;
	if (getInput("Enter your last name\n", lastName) == 1)
		return (1);
	std::string nickName;
	if (getInput("Enter your nick name\n", nickName) == 1)
		return (1);
	std::string phoneNumber;
	if (getInput("Enter your phone number\n", phoneNumber) == 1)
		return (1);
	std::string darkestSecret;
	if (getInput("Enter your darkest secret\n", darkestSecret) == 1)
		return (1);
	Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	phoneBook.addContact(contact);
	return (0);
}

int	main(void)
{
	clear();
	if (!std::cout.good())
		return (1);
	PhoneBook	phoneBook;
	std::cout << MENU_MSG;
	std::string	str;
	while (std::getline(std::cin, str) && str != "EXIT")
	{
		clear();
		if (str == "ADD")
			add(phoneBook);
		else if (str == "SEARCH")
			search(phoneBook);
		std::cout << MENU_MSG;
	}
	std::cout << "Exiting...\n";
}
