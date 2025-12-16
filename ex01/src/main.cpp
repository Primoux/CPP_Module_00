/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:54 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/16 17:44:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <stdio.h>

int	add(PhoneBook &phoneBook)
{
	std::string firstName;
	std::cout << "Enter first name\n";
	std::cin >> firstName;
	std::string lastName;
	std::cout << "Enter last name\n";
	std::cin >> lastName;
	std::string nickName;
	std::cout << "Enter nick name\n";
	std::cin >> lastName;
	std::string phoneNumber;
	std::cout << "Enter phone number\n";
	std::cin >> phoneNumber;
	std::string darkestSecret;
	std::cout << "Enter darkest secret\n";
	std::cin >> darkestSecret;
	Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	phoneBook.addContact(contact);
	return (0);
}

int	main(void)
{
	PhoneBook	phoneBook;

	if (!std::cout.good())
		return (1);
	std::string str;
	while (std::cin >> str && str != "EXIT")
	{
		if (str == "ADD")
			add(phoneBook);
		else if (str == "SEARCH")
			std::cout << "SEARCHING\n";
	}
}
