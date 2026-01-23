/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:54 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/23 12:13:17 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "define.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using std::endl;
using std::string;

void	clearTerm(void)
{
	std::system("clear");
}

void	search(PhoneBook phoneBook)
{
	clearTerm();
	if (phoneBook.printPhoneBook() == 1)
		return ;
	std::cout << "Enter the index of the contact [1]-[" << MAX_CONTACT << "]" << endl;
	string index;
	std::getline(std::cin, index);
	clearTerm();
	std::stringstream ss(index);
	int	i;
	if (index.empty() || (ss >> i).fail() || !ss.eof())
	{
		std::cout << "Invalid index\n" << endl;
		return ;
	}
	if (i < 1 || i > MAX_CONTACT)
	{
		std::cout << "Index out of range\n" << endl;
		return ;
	}
	phoneBook.printPhoneBook(i - 1);
}

int	getInput(string prompt, string &str)
{
	std::cout << prompt;
	while (std::getline(std::cin, str))
	{
		if (!str.empty())
			break;
		clearTerm();
		std::cout << "Error\nThe string is empty\n" << endl;
		std::cout << prompt;
	}
	clearTerm();
	return (std::cin.fail());
}

int	add(PhoneBook &phoneBook)
{
	clearTerm();
	string firstName;
	if (getInput("Enter your first name\n\n- ", firstName) == 1)
		return (1);
	string lastName;
	if (getInput("Enter your last name\n\n- ", lastName) == 1)
		return (1);
	string nickName;
	if (getInput("Enter your nick name\n\n- ", nickName) == 1)
		return (1);
	string phoneNumber;
	if (getInput("Enter your phone number\n\n- ", phoneNumber) == 1)
		return (1);
	string darkestSecret;
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
	string	str;
	while (std::getline(std::cin, str) && str != "EXIT")
	{
		clearTerm();
		if (str == "ADD")
		{
			if (add(phoneBook) == 1)
			{
				std::cout << ERROR_MSG << endl;
				return (1);
			}
		}
		else if (str == "SEARCH")
			search(phoneBook);
		std::cout << MENU_MSG;
	}
	std::cout << "Exiting..." << endl;
}
