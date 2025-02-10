/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:14:46 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:33:50 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl entered the McDo" << std::endl;
	actions[0].level = "DEBUG";
	actions[0].func = &Harl::debug;
	actions[1].level = "INFO";
	actions[1].func = &Harl::info;
	actions[2].level = "WARNING";
	actions[2].func = &Harl::warning;
	actions[3].level = "ERROR";
	actions[3].func = &Harl::error;
}

Harl::Harl(const Harl &other)
{
	*this = other;
}

Harl &Harl::operator=(const Harl &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			actions[i] = other.actions[i];
	}
	return *this;
}

Harl::~Harl()
{
	std::cout << "Harl leaved the McDo" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; ++i)
	{
		if (actions[i].level == level)
		{
			(this->*actions[i].func)();
			return;
		}
	}
    std::cout << "Invalid level: '" << level << "'" << std::endl;
}
