/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:39:29 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 11:40:30 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Color.hpp"

WrongAnimal::WrongAnimal(void) : type("")
{
	std::cout << GREEN_COLOR << "WrongAnimal default void constructor" << RESET_COLOR << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << GREEN_COLOR << "WrongAnimal default constructor with type '" << type << "'" << RESET_COLOR << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << GREEN_COLOR << "WrongAnimal copy constructor" << RESET_COLOR << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << PURPLE_COLOR << "WrongAnimal destructor of type '" << type << "' called" << RESET_COLOR << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << WHITE_COLOR << "[WrongAnimal] " << CYAN_COLOR << "rawwruuuiiuuilll boouimm" << RESET_COLOR << std::endl;
}
