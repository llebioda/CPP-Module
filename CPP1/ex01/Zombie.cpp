/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:59:19 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:35:02 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("a secondary character")
{
	std::cout << "A necromancer revived a new secondary character" << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << "A necromancer revived : " << name << std::endl;
	this->name = name;
}

Zombie::Zombie(const Zombie &other)
{
	*this = other;
}

Zombie &Zombie::operator=(const Zombie &other)
{
	if (this != &other)
	{
		name = other.name;
	}
	return *this;
}

Zombie::~Zombie()
{
	std::cout << name << " died" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
