/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:15:35 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/24 05:22:09 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0)
{
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	*this = other;
}

PhoneBook &PhoneBook::operator=(const PhoneBook& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 8; i++)
		{
			contacts[i] = other.contacts[i];
		}
		index = other.index;
	}
	return *this;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(Contact newContact)
{
	contacts[index % 8] = newContact;
	index++;
}

bool PhoneBook::searchContacts()
{
	bool isPhoneBookEmpty = true;
	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].isEmpty())
		{
			isPhoneBookEmpty = false;
			break;
		}
	}

	if (isPhoneBookEmpty)
	{
		std::cout << "The Phone Book is empty, ADD Contact before searching for one" << std::endl;
		return false;
	}

	std::cout << "   Index  |First Name| Last Name| Nickname " << std::endl;
	std::cout << "----------+----------+----------+----------" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].isEmpty())
		{
			contacts[i].displayShortInfo(i);
		}
	}
	return true;
}

void PhoneBook::displayContact(int idx)
{
	if (idx < 0 || idx >= 8 || contacts[idx].isEmpty())
	{
		std::cout << "Invalid index!" << std::endl;
	}
	else
	{
		contacts[idx].displayFullInfo();
	}
}