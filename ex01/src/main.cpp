/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:54 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/16 20:45:57 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <stdio.h>

void search(PhoneBook phoneBook)
{
	std::system("clear");
	if (phoneBook.printPhoneBook() == 1)
		return;
	std::cout << "Enter the index of the contact [0]-[8]\n";
	std::string index;
	std::cin >> index;
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
