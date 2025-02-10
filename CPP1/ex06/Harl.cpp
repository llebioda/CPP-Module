/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:14:46 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:34:01 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::Harl(const Harl &other)
{
	*this = other;
}

Harl &Harl::operator=(const Harl &other)
{
	(void)other;
	return *this;
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

Harl::Level Harl::str2level(const char* str)
{
    return strcmp(str, "DEBUG") == 0 ? DEBUG :
           strcmp(str, "INFO") == 0 ? INFO :
           strcmp(str, "WARNING") == 0 ? WARNING :
           strcmp(str, "ERROR") == 0 ? ERROR :
           INVALID;
}

void Harl::complain(std::string level)
{
	switch (str2level(level.c_str()))
	{
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
