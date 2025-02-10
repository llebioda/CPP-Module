/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:15:35 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/31 15:23:33 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string& strtrim(std::string& str)
{
	str = str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
	return str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
}

bool isStringEmpty(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

bool isValidPhoneNumberString(const std::string str)
{
	int digitCount = 0;

	if (isStringEmpty(str))
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]) && !std::isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return false;
		if (std::isdigit(str[i]))
			digitCount++;
	}
	return digitCount >= 9 && digitCount <= 13;
}

std::string getInput(const std::string &field, bool trimInput)
{
	std::string input = "";

	while (isStringEmpty(input) && !std::cin.eof())
	{
		std::cout << field << ": ";
		std::getline(std::cin, input);
		if (isStringEmpty(input))
		{
			std::cout << "This field cannot be empty. Please enter a valid " << field << "." << std::endl;
			input = "";
			continue;
		}
		if (trimInput)
			input = strtrim(input);
	}
	return input;
}

std::string getPhoneNumberInput()
{
	std::string input = "";

	while (!isValidPhoneNumberString(input) && !std::cin.eof())
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, input);
		if (isStringEmpty(input))
		{
			std::cout << "This field cannot be empty. Please enter a valid Phone Number." << std::endl;
			input = "";
		}
		else if (!isValidPhoneNumberString(input))
		{
			std::cout << "This is not a phone number. Please enter a valid Phone Number." << std::endl;
			input = "";
		}
	}
	return input;
}

int getValidIdx()
{
    int idx;
    while (!std::cin.eof())
	{
        std::cin >> idx;
        if (std::cin.fail())
		{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid id. Please enter a valid id: ";
        }
        else if (idx < 0 || idx >= 8)
		{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid id. Please enter a valid id between 0 and 7: ";
        }
		else
		{
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return idx;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (!std::cin.eof())
	{
		std::getline(std::cin, command);

		if (!std::cin)
		{
			std::cout << "Error" << std::endl;
			break;
		}

		command = strtrim(command);

		if (command == "ADD")
		{
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

			firstName = getInput("First Name", true);
			if (std::cin.eof())
				break;

			lastName = getInput("Last Name", true);
			if (std::cin.eof())
				break;

			nickname = getInput("Nickname", true);
			if (std::cin.eof())
				break;

			phoneNumber = getPhoneNumberInput();
			if (std::cin.eof())
				break;

			darkestSecret = getInput("Darkest Secret", false);
			if (std::cin.eof())
				break;

			Contact newContact;
			newContact.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.searchContacts())
			{
				std::cout << "Enter id to display more info: ";
				int idx = getValidIdx();
				phoneBook.displayContact(idx);
			}
		}
		else if (command == "EXIT")
		{
			break;
		}
	}
	
	return 0;
}
