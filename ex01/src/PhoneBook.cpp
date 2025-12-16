/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:59:27 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/16 17:40:59 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : max(8), index(0), current(0)
{
}
PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(Contact contact)
{
    this->array[this->index ] = contact;
    this->current++;
}
