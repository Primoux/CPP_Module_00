/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:54 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/17 15:22:59 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

void	search(PhoneBook phoneBook)
{
	int	i;

	std::system("clear");
	if (phoneBook.printPhoneBook() == 1)
		return ;
	std::cout << "Enter the index of the contact [0]-[8]\n";
	std::string index;
	std::cin >> index;
	std::system("clear");
	std::stringstream ss(index);
	if ((ss >> i).fail() || !ss.eof())
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (i < 0 || i > 8)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	phoneBook.printPhoneBook(i);
}

int	add(PhoneBook &phoneBook)
{
	std::system("clear");
	std::string firstName;
	std::cout << "Enter your first name\n";
	std::cin >> firstName;
	std::system("clear");
	std::string lastName;
	std::cout << "Enter your last name\n";
	std::cin >> lastName;
	std::system("clear");
	std::string nickName;
	std::cout << "Enter your nick name\n";
	std::cin >> nickName;
	std::system("clear");
	std::string phoneNumber;
	std::cout << "Enter your phone number\n";
	std::cin >> phoneNumber;
	std::system("clear");
	std::string darkestSecret;
	std::cout << "Enter your darkest secret\n";
	std::cin >> darkestSecret;
	std::system("clear");
	Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	phoneBook.addContact(contact);
	std::cout << "Added the contact " << firstName << " to the phonebook\n";
	return (0);
}

int	main(void)
{
	PhoneBook	phoneBook;

	if (!std::cout.good())
		return (1);
	std::string str;
	std::system("clear");
	std::cout << "'ADD' to add a contact\n'SEARCH' to enter the search mod\n'EXIT' to exit the program\n";
	while (std::cin >> str && str != "EXIT")
	{
		std::system("clear");
		if (str == "ADD")
			add(phoneBook);
		else if (str == "SEARCH")
			search(phoneBook);
		std::cout << "'ADD' to add a contact\n'SEARCH' to enter the search mod\n'EXIT' to exit the program\n";
	}
	std::cout << "Exiting...\n";
}
