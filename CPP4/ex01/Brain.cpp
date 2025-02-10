/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:35:36 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 13:32:32 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << MAGENTA_COLOR << "Brain default constructor" << RESET_COLOR << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << MAGENTA_COLOR << "Brain copy constructor" << RESET_COLOR << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i].assign(other.ideas[i]);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << BLUE_COLOR << "Brain destructor called" << RESET_COLOR << std::endl;
}

std::string Brain::getIdeas(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cerr << "Invalid index '" << index << "'" << std::endl;
		return "";
	}
	return ideas[index];
}

void Brain::setIdeas(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cerr << "Invalid index '" << index << "'" << std::endl;
		return ;
	}
	ideas[index] = idea;
}
