/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:08:21 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 13:32:29 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), brain(new Brain())
{
	std::cout << GREEN_COLOR << "Dog default constructor" << RESET_COLOR << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog"), brain(new Brain())
{
	*this = other;
	std::cout << GREEN_COLOR << "Dog copy constructor" << RESET_COLOR << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *(other.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << PURPLE_COLOR << "Dog destructor called" << RESET_COLOR << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << WHITE_COLOR << "[Dog] " << CYAN_COLOR << "waf woof waf" << RESET_COLOR << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return brain;
}
