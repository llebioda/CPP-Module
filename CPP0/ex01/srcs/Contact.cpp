/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:15:35 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/24 03:57:59 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(): firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("")
{
}

Contact::Contact(const Contact& other)
{
	*this = other;
}

Contact &Contact::operator=(const Contact& other)
{
	if (this != &other)
	{
		firstName = other.firstName;
		lastName = other.lastName;
		nickname = other.nickname;
		phoneNumber = other.phoneNumber;
		darkestSecret = other.darkestSecret;
	}
	return *this;
}

Contact::~Contact()
{
}

std::string Contact::truncateString(std::string str)
{
	return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

void Contact::addContact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void Contact::displayShortInfo(int index)
{
	std::cout
		<< std::setw(10) << index << "|"
		<< std::setw(10) << truncateString(firstName) << "|"
		<< std::setw(10) << truncateString(lastName) << "|"
		<< std::setw(10) << truncateString(nickname) << std::endl;
}

void Contact::displayFullInfo()
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty()
{
	return firstName.empty() && lastName.empty() && nickname.empty() &&
			phoneNumber.empty() && darkestSecret.empty();
}