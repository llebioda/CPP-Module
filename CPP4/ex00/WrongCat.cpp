/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:41:40 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 11:43:47 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << GREEN_COLOR << "WrongCat default constructor" << RESET_COLOR << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal("WrongCat")
{
	*this = other;
	std::cout << GREEN_COLOR << "WrongCat copy constructor" << RESET_COLOR << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << PURPLE_COLOR << "WrongCat destructor called" << RESET_COLOR << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << WHITE_COLOR << "[WrongCat] " << CYAN_COLOR << "meeeeewwoowww ?" << RESET_COLOR << std::endl;
}
