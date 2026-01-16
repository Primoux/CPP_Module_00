/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:54 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/16 10:44:24 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "define.h"
#include <cstdio>
#include <cstdlib>
#include <ostream>
#include <sstream>
#include <iostream>
#include <string>

void	clearTerm(void)
{
	std::system("clear");
}

void	search(PhoneBook phoneBook)
{
	clearTerm();
	if (phoneBook.printPhoneBook() == 1)
		return ;
	std::cout << "Enter the index of the contact [1]-[" << MAX_CONTACT << "]" << std::endl;
	std::string index;
	std::getline(std::cin, index);
	clearTerm();
	std::stringstream ss(index);
	int	i;
	if (index.empty() || (ss >> i).fail() || !ss.eof())
	{
		std::cout << "Invalid index\n" << std::endl;
		return ;
	}
	if (i < 1 || i > MAX_CONTACT)
	{
		std::cout << "Index out of range\n" << std::endl;
		return ;
	}
	phoneBook.printPhoneBook(i - 1);
}

int	getInput(std::string prompt, std::string &str)
{
	std::cout << prompt;
	while (std::getline(std::cin, str))
	{
		if (!str.empty())
			break;
		clearTerm();
		std::cout << "Error\nThe string is empty\n" << std::endl;
		std::cout << prompt;
	}
	clearTerm();
	return (std::cin.fail());
}

int	add(PhoneBook &phoneBook)
{
	clearTerm();
	std::string firstName;
	if (getInput("Enter your first name\n\n- ", firstName) == 1)
		return (1);
	std::string lastName;
	if (getInput("Enter your last name\n\n- ", lastName) == 1)
		return (1);
	std::string nickName;
	if (getInput("Enter your nick name\n\n- ", nickName) == 1)
		return (1);
	std::string phoneNumber;
	if (getInput("Enter your phone number\n\n- ", phoneNumber) == 1)
		return (1);
	std::string darkestSecret;
	if (getInput("Enter your darkest secret\n\n- ", darkestSecret) == 1)
		return (1);
	Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	phoneBook.addContact(contact);
	return (0);
}

int	main(void)
{
	clearTerm();
	PhoneBook	phoneBook;
	std::cout << MENU_MSG;
	std::string	str;
	while (std::getline(std::cin, str) && str != "EXIT")
	{
		clearTerm();
		if (str == "ADD")
		{
			if (add(phoneBook) == 1)
			{
				std::cout << ERROR_MSG << std::endl;
				return (1);
			}
		}
		else if (str == "SEARCH")
			search(phoneBook);
		std::cout << MENU_MSG;
	}
	std::cout << "Exiting...\n";
}
