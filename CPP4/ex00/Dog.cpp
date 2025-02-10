/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:08:21 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 11:29:37 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << GREEN_COLOR << "Dog default constructor" << RESET_COLOR << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	*this = other;
	std::cout << GREEN_COLOR << "Dog copy constructor" << RESET_COLOR << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << PURPLE_COLOR << "Dog destructor called" << RESET_COLOR << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << WHITE_COLOR << "[Dog] " << CYAN_COLOR << "waf woof waf" << RESET_COLOR << std::endl;
}
