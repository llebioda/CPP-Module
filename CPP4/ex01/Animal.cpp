/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:50:05 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 13:10:44 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Color.hpp"

Animal::Animal(void) : type("")
{
	std::cout << GREEN_COLOR << "Animal default void constructor" << RESET_COLOR << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << GREEN_COLOR << "Animal default constructor with type '" << type << "'" << RESET_COLOR << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << GREEN_COLOR << "Animal copy constructor" << RESET_COLOR << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << PURPLE_COLOR << "Animal destructor of type '" << type << "' called" << RESET_COLOR << std::endl;
}

std::string Animal::getType(void) const
{
	return type;
}

void Animal::makeSound(void) const
{
	std::cout << WHITE_COLOR << "[Animal] " << RED_COLOR << "The abstract class Animal cannot make a sound" << RESET_COLOR << std::endl;
}

Brain *Animal::getBrain(void) const
{
	return NULL;
}