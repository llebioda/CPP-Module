/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:08:21 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 11:29:48 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << GREEN_COLOR << "Cat default constructor" << RESET_COLOR << std::endl;
}

Cat::Cat(const Cat &other) : Animal("Cat")
{
	*this = other;
	std::cout << GREEN_COLOR << "Cat copy constructor" << RESET_COLOR << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << PURPLE_COLOR << "Cat destructor called" << RESET_COLOR << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << WHITE_COLOR << "[Cat] " << CYAN_COLOR << "meowww" << RESET_COLOR << std::endl;
}
